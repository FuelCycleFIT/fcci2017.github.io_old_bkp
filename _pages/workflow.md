---
layout: page
title: Workflow
---

# Experiment's philosophy

The FCCI exercices are based on a specific experiment representing a fleet modelization. Each fleet is described by a set of interesting output metrics, input variables and parameteres and facilities model features.

The goal of the full problem is to calulate the output metrics sensitivity to the input parameter, the facility model features and/or to the different input simplifications applied to the fuel cycle simulation.

For this purpose, a set of question/problems with an increasing complexity is proposed to guide up to the final exercice representing the full cycle modelisation. First exercices consists of small set of facility combined together according to the advancement in the experiment.

Exercices could be divided into three separated steps

1. Simple exercices with fixed input factors

Small numbers of facilities are simulated chosen from the full fleet simplification. Input factors and simplifications are fixed. Those exercices highlights differences or agreements between different tools at the scale of the facility.

2. Full fleet exercices with fixed input factors

The full fleet is  simulated from a set of fixed input factors and simplifications. Differences or agreements between different tools at the scale of the fleet is assessed.

3. Full fleet exercice with variable input factors

From the full fleet modelization, a complete sensitivity analysis is run by sampling in a specified range all the input factors and available simplifications. Impact of differences assessed during exercices set 1. and 2. is measured.






In the follow one can find an example of what a test should look like:

# Design of Experience

## Introduction

General description of the goal of the experiement, and the general application cases:
*ex radio-protection, cost evaluation/economical study, non-proliferation, fuel
cycle evaluation, ...*

## Cycle Description
Exhaustiv description of the cycle we aim to simulate, allowing the simulator to
have a global ideas of the complete cycle.
This should describe in details all the type of facilities presents in the
simulation as well as all the different possible material flows. This might be
documented with a cycle pictures allowing a better understanding of the
simulation.

## Output Metrics
Description of all the differents identified output metrics relevants for the
considered test.

Metrics can be deferencied into 2 categories:

- direct output metrics, which should directly be produced by a generic fuel
  cycle tool, as material flows, materials compositions, power generated,
  ressource comsubsion...

- indirect ouput metrics, that require addition computations to be determine, such as
  cost, radio-toxicity, decayheat....


## Cycle Input and Model simplification
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
