/*************************************************/
//              DESCRIPTION
// Simple scenario :
// This park is constituted by a PWR UOX, a PWR MOx for PERMIS exo 1
// Pool, FP, and storage
//
//@author Nico
/*************************************************/
#include "CLASSHeaders.hxx"
#include <sstream>
#include <iomanip>
#include <math.h>
#include <string>

#include "XS/XSM_MLP.hxx"			
#include "Irradiation/IM_RK4.hxx"	
#include "Equivalence/EQM_PWR_POL_UO2.hxx"
#include "Equivalence/EQM_MLP_Kinf.hxx"

using namespace std;

int main(int argc, char** argv)
{

	cSecond year = 3600*24.*365.25; 

	//##########################################################################################
	//####### USE ##############################################################################
	//##########################################################################################

	if (argc != 11)
	{
		cout<<"#############################################"<<endl;
		cout<<"#############################################"<<endl<<endl;
		cout<<"USE : "<<endl<<endl;
		cout<<"CLASS_Exec BU_UOx LoadFactorUOx BU_MOX LoadFactorMOx KseuilMOX NumberOfBatches FractionMOX TFabMOX TCooling StockManagment"<<endl<<endl;;
		cout<<"EXAMPLE : "<<endl<<endl;
		cout<<"CLASS_Exec 40 0.80 45 0.75 1.03 3 0.10 2 5 1"<<endl<<endl;;
		cout<<"#############################################"<<endl<<endl;;
		cout<<"#############################################"<<endl;
		exit(1);
	}

	//##########################################################################################
	//####### PARAMETERS #######################################################################
	//##########################################################################################

	double BU_UOX 			= atof(argv[1]); // [25 - 75]
	double LoadFactorUOx 	= atof(argv[2]); // FIXED

	double BU_MOX 			= atof(argv[3]); // [25 - 75]
	double LoadFactorMOx	= atof(argv[4]); // FIXED
	double KseuilMOX		= atof(argv[5]); // FIXED
	int NumberOfBatches		= atof(argv[6]); // [3 - 4]

	double FractionMOX 		= atof(argv[7]); // [0 - 20]

	cSecond TFabMOX			= (cSecond)(atof(argv[8])); // [0 - 3]
	cSecond TCooling 		= (cSecond)(atof(argv[9])); // [1 - 15]

	int StockManagment 		= atoi(argv[10]); // 1 = kpLiFo, 2 = kpFiFo, 3 = kpMix
	StorageManagement SM;
	if (StockManagment == 1)		SM = kpLiFo;
	else if (StockManagment == 2)	SM = kpFiFo;
	else if (StockManagment == 3)	SM = kpMix;
	else {cout<<endl<<"StockManagement should be 1, 2 or 3... EXIT"<<endl<<endl; exit(1);}

	//##########################################################################################
	//####### SCENARIO DATA ####################################################################
	//##########################################################################################

	cSecond d_TimeStep 		= year / 12.;//atof(s_TimeStep.c_str()); 		// arg should be in seconds
	cSecond d_TimeScenario	= 100*year  ;//atof(s_TimeScenario.c_str()); 	// arg should be in seconds
	string s_DirFileName 		= string("OUT")
								+ string("_") + argv[1] + string("_") + argv[2] + string("_") + argv[3] + string("_") + argv[4] + string("_") + argv[5]
								+ string("_") + argv[6] + string("_") + argv[7] + string("_") + argv[8] + string("_") + argv[9] + string("_") + argv[10];
	string s_CMD = 	string("mkdir ") + s_DirFileName;					
	system(s_CMD.c_str());
	string s_FileName 		= s_DirFileName + string("/OUT.root");

	//##########################################################################################
	//####### LOG MANAGEMENT ###################################################################
	//##########################################################################################

	int Std_output_level 	= 0; //Only error are shown in terminal
	int File_output_level 	= 0; // Error + Warning + Info are shown in the file CLASS_OUTPUT.log
	CLASSLogger *Logger 	= new CLASSLogger("CLASS_OUTPUT.log",Std_output_level,File_output_level);

	//##########################################################################################
	//####### SCENARIO #########################################################################
	//##########################################################################################

	Scenario *gCLASS=new Scenario(0*year,Logger);
	gCLASS->SetStockManagement(true);					//If false all the IsotopicVector in stocks are mixed together.
	gCLASS->SetTimeStep((double)d_TimeStep);
	gCLASS->SetOutputFileName(s_FileName);				//Set the name of the output file
	gCLASS->SetSoberTerminalOutput();
	gCLASS->SetZAIThreshold(82);

	//##########################################################################################
	//####### DATABASE #########################################################################
	//##########################################################################################

    string CLASS_PATH = getenv("CLASS_PATH");
    string PATH_TO_DATA = CLASS_PATH + "/DATA_BASES/";

   	// DECAY
	DecayDataBank* DecayDB = new DecayDataBank(gCLASS->GetLog(), PATH_TO_DATA + "DECAY/ALL/Decay.idx");
	gCLASS->SetDecayDataBase(DecayDB);

	// Bateman Solver
	IM_RK4*			IMRK4 		= new IM_RK4(gCLASS->GetLog());

	// REP UOX
	XSM_MLP* 			XSMUOX 		= new XSM_MLP(gCLASS->GetLog(), PATH_TO_DATA + "PWR/UOX/XSModel/30Wg_FullUOX");
	EQM_PWR_POL_UO2*	EQMPWRUOX 	= new EQM_PWR_POL_UO2(gCLASS->GetLog(),PATH_TO_DATA + "PWR/UOX/EQModel/PWR_900_30Wg_third/weight.dat");
	PhysicsModels*		PMUOX		= new PhysicsModels(XSMUOX, EQMPWRUOX, IMRK4);

	// REP MOx 
	XSM_MLP* 			XSMMOX 		= new XSM_MLP(gCLASS->GetLog(), PATH_TO_DATA + "PWR/MOX/XSModel/30Wg_FullMOX");
	EQM_MLP_Kinf* 		EQMPWRMOX 	= new EQM_MLP_Kinf(gCLASS->GetLog(),PATH_TO_DATA + "PWR/MOX/EQModel/MLP_Kinf/MLP/PWR_MOX_30Wg.xml",NumberOfBatches,"",KseuilMOX);
	//EQMPWRMOX->SetRelativMassPrecision(1./1000.);
	PhysicsModels*		PMMMOX		= new PhysicsModels(XSMMOX, EQMPWRMOX, IMRK4);

	//##########################################################################################
	//####### IV ###############################################################################
	//##########################################################################################
	//
	//##########################################################################################
	//####### STORAGE ##########################################################################
	//##########################################################################################
 
	Storage *StockUOx = new Storage(gCLASS->GetLog());
	StockUOx->SetName("StockUOx");
	gCLASS->Add(StockUOx);

	Storage *StockMOx = new Storage(gCLASS->GetLog());
	StockMOx->SetName("StockMOx");
	gCLASS->Add(StockMOx);

	//##########################################################################################
	//####### SEPARATION PLANT #################################################################
	//##########################################################################################

	//##########################################################################################
	//####### POOL #############################################################################
	//##########################################################################################

	Pool *PoolUOx = new Pool(gCLASS->GetLog(),StockUOx, TCooling*year);
	PoolUOx->SetName("PoolUOx");
	gCLASS->Add(PoolUOx);

	Pool *PoolMOx = new Pool(gCLASS->GetLog(),StockMOx, 5*year);
	PoolMOx->SetName("PoolMOx");
	gCLASS->Add(PoolMOx);

	//##########################################################################################
	//####### FABRICATION PLANT #################################################################
	//##########################################################################################

	FabricationPlant *FP_UOX = new FabricationPlant(gCLASS->GetLog(), 0*year);
	FP_UOX->SetName("Fab_UOX");
	FP_UOX->AddInfiniteStorage("Fissile");
	FP_UOX->AddInfiniteStorage("Fertile");
	gCLASS->AddFabricationPlant(FP_UOX);

	FabricationPlant *FP_MOX = new FabricationPlant(gCLASS->GetLog(), TFabMOX*year);
	FP_MOX->SetStorageManagement(SM);
	FP_MOX->SetSeparationManagement(true);
	FP_MOX->SetName("Fab_MOX");
	FP_MOX->AddStorage("Fissile", StockUOx);
	FP_MOX->AddInfiniteStorage("Fertile");
	gCLASS->AddFabricationPlant(FP_MOX);

	//##########################################################################################
	//####### REACTOR ##########################################################################
	//##########################################################################################

	cSecond TimeStartMox = 22.5*year;
	
	//##########################################################################################
	//####### REP UOX ##########################################################################
	//##########################################################################################

	double N_UOx 	= 1;

	double HMMass 		= 72.3	 * N_UOx;
	double Power 		= 2785e6 * N_UOx;
	double BurnUp 		= BU_UOX;
	//double CycleTime 	= 4.5*year;
	//double LoadFactor 	= BurnUp * HMMass / (Power/1.e9) / (CycleTime/(3600.*24.));
	double LoadFactor 	= LoadFactorUOx;

	cSecond StartingTime =  0*year;
	cSecond LifeTime     =  100*year;
	
	Reactor* PWR_UOX = new Reactor(gCLASS->GetLog(),PMUOX,FP_UOX,PoolUOx,StartingTime,LifeTime,Power,HMMass,BurnUp,LoadFactor);
	PWR_UOX->AddScheduleEntry(TimeStartMox, PMUOX, BurnUp, Power*(1 - FractionMOX), HMMass*(1 - FractionMOX));

	PWR_UOX->SetName("PWR_UOx");
	gCLASS->AddReactor(PWR_UOX);

	//##########################################################################################
	//####### REP MOX ##########################################################################
	//##########################################################################################

	double N_MOx 	= FractionMOX; // MOX Fraction in the fleet (ex : 0.1)

	HMMass 		= 72.3	 * N_MOx;
	Power 		= 2785e6 * N_MOx;
	BurnUp 		= BU_MOX;
	//CycleTime 	= 4.5*year;
	//LoadFactor 	= BurnUp * HMMass / (Power/1.e9) / (CycleTime/(3600.*24.));
	LoadFactor 	= LoadFactorMOx;

	StartingTime =  TimeStartMox;
	LifeTime     =  500*year;
	
	Reactor* PWR_MOX = new Reactor(gCLASS->GetLog(),PMMMOX,FP_MOX,PoolMOx,StartingTime,LifeTime,Power,HMMass,BurnUp,LoadFactor);

	PWR_MOX->SetName("PWR_MOX");
	gCLASS->AddReactor(PWR_MOX);

	//##########################################################################################
	//####### EVOLUTION ########################################################################
	//##########################################################################################

	gCLASS->Evolution((double)d_TimeScenario);

	//##########################################################################################
	//####### OUTPUT ###########################################################################
	//##########################################################################################

	// INPUT PARAMETERS
	// CYCLE TIME UOX
	// CYCLE TIME MOX

	//cout<<"LoadFactor PWR - UOx :"<<LoadFactor<<endl;
	//cout<<StartingTime<<" "<<LifeTime<<" "<<Power<<" "<<HMMass<<" "<<BurnUp<<" "<<LoadFactor<<endl<<endl;;

	//cout<<"LoadFactor PWR - MOx :"<<LoadFactor<<endl;
	//cout<<StartingTime<<" "<<LifeTime<<" "<<Power<<" "<<HMMass<<" "<<BurnUp<<" "<<LoadFactor<<endl<<endl;


	delete gCLASS;
}

//==========================================================================================
// Compilation
//==========================================================================================
/*
 
 g++ -o CLASS_Exec InputClass.cxx -I $CLASS_include -L $CLASS_lib -lCLASSpkg `root-config --cflags` `root-config --libs` -fopenmp -lgomp
 
 
 */
