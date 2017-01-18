==============================
LEXICON
==============================

## Scenario

A scenario is constituted by the following set :

	- Input
	- Model
	- Output

It defines a well defined trajectory for a nuclear fleet evolution on a given time frame.

## Input

Self consistant set of input parameters and factors that allows the complete description of the simulated scenario.

### Input variable

An input variable is a factor that is observable in a real fleet and has to be defined by the user. Input variable can be ordonnated: 

	- Time range
	- Cycle units (facilities and connections)
	- Facilities parameters (BU, cooling time, tail assets, power, etc.)
	- Facilities evolution

Or not ordonnated:

	- Separation : On demand or on line
	- Fuel strategy : FiFo, LiFo, Random...

### Input parameter

An input parameter is not measurable in the real fleet and has to be estimated.

	- Reactivity threshold for maximal burn up
	- Time steps
	- ...?

### Input simplifications

	- One or several dephased reactors
	- With or without reactor first loading
	- other...

## Model

Represents the computationnal tool that processes the input and performing output calculation, according to this figure:

![Fuel cycle simulation scheme](FIG/MODEL.png)

Here's a non exhaustive list of models : 

	- CYCLUS
	- CLASS
	- COSI

A fuel cycle model includes sub models for each facility we want to modelize. Usually facility model simplifications are used to for optimizing CPU calculation time trying to not impacting the output. Simplifications have to be done according to targetted output variables.

### Facility model 

A facility model is defined by its features.

	- Fabrication plant : 

		- Relation between storage and targeted burn up (Always same fissile fraction, mathematical relation, neural network, etc.)
		- Performing separation or not

	- Reactor : 
	
		- Bateman solver or recipe based depletion
		- With or without fuel loading pattern neighborhood
		- Fixed burn up or fixed cycle time
		- Predictors from assembly calculation
		- ...

	- Pool and storage : 
		- With or Without decay

	- Storage
		- Materials mixed or sorted according to time

## Output

### Direct output

An direct output is composed by raw data calculated by the model according to inputs.

###	Indirect output

Indirect outputs are all data calculated from direct output after one or several operations.

## Design of experiment

Design Of Experiment is the range of variation for Input variables and parameters

## Metric

  A metric defines a set of observables with associated unit.





