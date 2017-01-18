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
The present experiement cycle will be composed by an fabrication plant, which
enricht a natural uranium feed (0.3%<sub>w</sub> of <sup>235</sup>U + 99.7%<sub>w</sub> of <sup>238</sup>U)
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
        - Specific Power[GW/t<sub>HM</sub>]: [X .. Y]
        - Capacity Factor: [X .. Y]
        - Cycle Time: Set to match Burnup specification
        - Burnup [GWd/t<sub>HM</sub>]: [X .. Y] 
        - Mass [t<sub>HM</sub>]: [X .. Y] 
        - laoding patern[core fraction]: [1, 3, 4]
        - loading time[month]: [0, 1]
      - Enrichment:
        - tails[%<sub>w</sub>]: [X .. Y]
        - UOX[%<sub>w</sub>]: [X .. Y]

    - Model:
      - Decay (Depletion excluded): [on/off]
      - Fuel Fab modelisation: 
        - Fix: see UOX enrichment
        - Loading model: Free Parameter (Consider as much as possible)

      - Fuel depletion modelisation:
        - recipe 
        - Depletion: Free Parameter (Consider as much as possible)


## Do to

### Simple calculation

  1. Block 1

     Input variable:
       - Reactor:
         - Specific Power[GW/t<sub>HM</sub>]: val1, val2, valn 
         - Capacity Factor: val1, val2, valn 
         - Cycle Time: Set to match Burnup specification
         - Burnup [GWd/t<sub>HM</sub>]: val1, val2, valn 
         - Mass [t<sub>HM</sub>]: val1, val2, valn  
         - laoding patern[core fraction]: val1, val2, valn 
         - loading time[month]: val1, val2, valn 

       - Enrichment:
         - tails[%<sub>w</sub>]: val1, val2, valn 
         - UOX[%<sub>w</sub>: val1, val2, valn 
     
     Model:
       - Decay (Depletion excluded): val1, val2, valn 
       - Fuel Fab modelisation: 
         - Fix: see UOX enrichment: val1, val2, valn 
         - Loading model: Free Parameter (Consider as much as possible)
       - Fuel depletion modelisation:
         - recipe 
         - Depletion: Free Parameter (Consider as much as possible)

  2. Block 2

     Input variable:
       - Reactor:
         - Specific Power[GW/t<sub>HM</sub>]: val1, val2, valn 
         - Capacity Factor: val1, val2, valn 
         - Cycle Time: Set to match Burnup specification
         - Burnup [GWd/t<sub>HM</sub>]: val1, val2, valn 
         - Mass [t<sub>HM</sub>]: val1, val2, valn  
         - laoding patern[core fraction]: val1, val2, valn 
         - loading time[month]: val1, val2, valn 

       - Enrichment:
         - tails[%<sub>w</sub>]: val1, val2, valn 
         - UOX[%<sub>w</sub>: val1, val2, valn 
     
     Model:
       - Decay (Depletion excluded): val1, val2, valn 
       - Fuel Fab modelisation: 
         - Fix: see UOX enrichment: val1, val2, valn 
         - Loading model: Free Parameter (Consider as much as possible)
       - Fuel depletion modelisation:
         - recipe 
         - Depletion: Free Parameter (Consider as much as possible)

### Full calculation
  

### Sensitivity Analysis
