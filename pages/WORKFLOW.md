========
WORKFLOW
========

General definition
==================

Each different part of the FCCI should be based on a specific experiment that we
want to answer.  For each problem a cycle will be defined as well as a set of
interesting output metrics input variable and modeling option.


The goal of the full problem will be to determine the sensitivity of the output
metrics to the input parameter, the modelisation option and/or to the different
hypothesis relative to the fuel cycle simulation.


To do so, one need to build a set of question/problems with an increasing
complexity. 
The first set will consist to the definition of simple set of elementary block
that are consistent together, which all put together will consistitute the full
cycle one aims to consider.
For each elementary blocks using a fix set a input parameters, modeling options
and hypothesis, a values of the ouput metrics will be provided. A first
comparison between the different tools and simulation parameters will allows to
understand the difference between the different tools/simulations, and ensure
that each tool and simualtion are working as expected.

The second part of the workflow will be dedicated to perfom on a limited number
of test cases the full cycle simulation. This will allow to run a first round of
comparison between tools and simulation option.


The last part of each problem, will consistant for each tool to run a sentisity
analysis to all the different simulation hypothesis parameters. Running a large
number of simulation shuffling input parameters, modeling options to be used to
run sensitivity analysis.


In the follow one can find an example of what a test should look like:

Design of Experience
====================

Introduction
------------

General description of the goal of the experiement, and the general application cases:
*ex radio-protection, cost evaluation/economical study, non-proliferation, fuel
cycle evaluation, ...*

Cycle Description
-----------------
Exhaustiv description of the cycle we aim to simulate, allowing the simulator to
have a global ideas of the complete cycle.
This should describe in details all the type of facilities presents in the
simulation as well as all the different possible material flows. This might be
documented with a cycle pictures allowing a better understanding of the
simulation.

Output Metrics
--------------
Description of all the differents identified output metrics relevants for the
considered test.

Metrics can be deferencied into 2 categories:

- direct output metrics, which should directly be produced by a generic fuel
  cycle tool, as material flows, materials compositions, power generated,
  ressource comsubsion...

- indirect ouput metrics, that require addition computations to be determine, such as
  cost, radio-toxicity, decayheat....


Cycle Input and Model simplification
------------------------------------
Description of the all the degree of freedom of the experiences:

- Definition of the input factors (variables and parameters) and their variation
  range/allowed values (if applicable), example:

  - burnup [ BU<sub>min</sub>, BU<sub>max</sub>]
  - FiFo/LiFo/random/mix
  - ...

- Definition of the model simplification considered in the experience, such as:

- depletion
  - fuel fabrication
  - decay
  - *loading pattern optimisation*

This part aims to identify the different degree of freedom of the input, on
which the sentivity will *in fine* be performed
