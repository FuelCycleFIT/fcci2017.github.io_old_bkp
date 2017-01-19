---
layout: page
title: Experiement 1
tagline: PWR UOX
description: This experiement has been designed to assess the correlataion of a
one through cycle composed by an enrichement factory, a PWR loaded with UOX fuel
and a storage to store the used UOX fuel.
---

# Design of Experience

## Introduction
This experiement has been designed to assess the correlataion of a
one through cycle composed by an enrichement factory, a PWR loaded with UOX fuel
and a storage to store the used UOX fuel.


## Cycle Description
The present experiement cycle will be composed by:
  - an fabrication plant, which enricht a natural uranium feed (0.3%<sub>w</sub> of <sup>235</sup>U + 99.7%<sub>w</sub> of <sup>238</sup>U)
  - 10 PWR reactor:
    - starting: TDB
    - lifetime: TDB
  - Storage
  - 1 Natural Uranium source
![Experiement 1 Shema](exp1.png)


## Output Metrics
- Unat consumption
- Waste:
  - Pu mass
  - vector Pu
  - MA mass
  - MA vector 
  - Decay Heat 


## Cycle Input and Model simplification
- Input variable:
 - Reactor:
   - Specific Power[GW/t<sub>HM</sub>]: [20 .. 30] (ref 30)
   - Capacity Factor **(fix)** : [0.75]
   - Cycle Time: Set to match Burnup specification
   - Burnup [GWd/t<sub>HM</sub>]: [25 .. 75] (ref 40) 
   - Mass [t<sub>HM</sub>]: [53.25 .. 112.25] (ref 75) 
   - Loading patern[core fraction]: [1, 3, 4, 5] (ref 3)
   - Loading time[month]: [0, 1]
 - Enrichment:
   - tails[%<sub>w</sub>]: [X .. Y]
   - <sup>235</sup>U in UOX[%<sub>w</sub>]: [3 .. 5] (ref 4)
- Model:
 - Decay (Depletion excluded): [on/off] (ref on if available)
 - Fuel Fab modelisation: 
   - Fix: see UOX enrichment
   - Loading model: Free Parameter (Consider as much as possible)
 - Fuel depletion modelisation:
   - recipe 
   - Depletion: Free Parameter (Consider as much as possible)
 - Time steps[month]: [1 .. 24] (ref 1)

## Do to

### Simple calculation

#### Problem 1
- 1 PWR UOX
- 1 enrichement factory
Calculation lenght: 1 reactor cycle
- Input variable:
  - Reactor:
    - Specific Power[GW/t<sub>HM</sub>]: val1, val2, valn 
    - Capacity Factor: val1, val2, valn 
    - Cycle Time: Set to match Burnup specification
    - Burnup [GWd/t<sub>HM</sub>]: val1, val2, valn 
    - Mass [t<sub>HM</sub>]: val1, val2, valn  
    - Loading patern[core fraction]: val1, val2, valn 
    - Loading time[month]: val1, val2, valn 
  - Enrichment:
    - tails[%<sub>w</sub>]: val1, val2, valn 
    - <sup>235</sup>U in UOX[%<sub>w</sub>]: val1, val2, valn
- Model:
  - Decay (Depletion excluded): val1, val2, valn 
  - Fuel Fab modelisation: 
    - Fix: see UOX enrichment: val1, val2, valn 
    - Loading model: Free Parameter (Consider as much as possible)
  - Fuel depletion modelisation:
    - recipe 
    - Depletion: Free Parameter (Consider as much as possible)

#### Problem 2
  - 2 PWR UOX
  - 1 enrichement factory
  - Calculation lenght: 1 reactor cycle
  - Input variable & Model: see Problem 1

#### Problem 3
  - 2 PWR UOX
    - starting: 0y and 50y
    - life time: 100y
  - 1 enrichement factory
  - 1 storage
  - Calculation lenght: 100 years
  - Input variable & Model: see Problem 1

#### Problem 4
  - 2 PWR UOX
    - starting: 0y and 50y
    - life time: 60y
  - 1 enrichement factory
  - 1 storage
  - Calculation lenght: 100 years
  - Input variable & Model: see Problem 1

#### Problem 5
  - 10 PWR UOX
    - starting: every 10y form 0y
    - life time: 60y
  - 1 enrichement factory
  - 1 storage
  - Calculation lenght: 100 years
  - Input variable & Model: see Problem 1

### Full calculation
  

### Sensitivity Analysis
