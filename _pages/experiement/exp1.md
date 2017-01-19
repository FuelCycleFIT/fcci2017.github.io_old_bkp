---
layout: page
title: Experiment 1
tagline: PWR-UOX, ! Through cycle 
description: This experiment has been designed to assess the correlation of a
one through cycle composed by an enrichment factory, a PWR loaded with UOX fuel
and a storage to store the used UOX fuel.
---

# Design of Experience

## Introduction
This experiment has been designed to assess the correlation of a
one through cycle composed by an enrichment factory, a PWR loaded with UOX fuel
and a storage to store the used UOX fuel.


## Cycle Description
The present experiment cycle will be composed by:
  - an fabrication plant, which enrich a natural uranium feed (0.3%<sub>w</sub> of <sup>235</sup>U + 99.7%<sub>w</sub> of <sup>238</sup>U)
  - 10 PWR reactor:
    - starting: first 0y then 1 every 10y
    - lifetime: 50y
  - 1 infinite storage
  - 1 infinite Natural Uranium source
  - Calculation length: 100yi
  - the totale energy production is a fix parameter
![Experiment 1 Schema](exp1.png)


## Output Metrics
- Unat consumption
- Waste:
  - Pu mass
  - vector Pu: [238, 239, 240, 241, 242]
  - MA mass
  - MA vector: [<sup>237</sup>Np, <sup>241</sup>Am, <sup>242m</sup>Am, <sup>243</sup>Am, <sup>243</sup>Cm, <sup>244</sup>Cm, <sup>245</sup>Cm,<sup>246</sup>Cm] 
  - Decay Heat 


## Cycle Input and Model simplification
- Input variable:
  - Variation range for each reactor:



    - **Effective Thermal Power [GW]: fixed**: 0.9 
      - Thermal Power : set to match Effective Thermal Power
      - Capacity Factor : set to match Effective Thermal Power
      P<sub>th-eff</sub> = C<sub>f</sub> * P<sub>th</sub>
    - Effective Specific Power[GW/t<sub>HM</sub>]: [20 .. 30]
    - Mass [t<sub>HM</sub>]: Set to match Effective Thermal Power:
      P<sub>th-eff</sub> = P<sub>eff-spec</sub> * M
    - Cycle Time: Set to match Burnup specification
    - Burnup [GWd/t<sub>HM</sub>]: [25 .. 75]
    - Loading pattern[core fraction]: [1, 3, 4, 5]
    - Loading time[month]: [0, 1]
- Enrichment:
   - tails[%<sub>w</sub>]: [0.05 .. 0.2]
   - <sup>235</sup>U in UOX[%<sub>w</sub>]: [3 .. 5]
- Model:
  - Decay (Depletion excluded): [on/off]
  - Fuel Fab mobilisation: 
    - Fix: see UOX enrichment
    - Loading model (Consider as much as possible), example of parameter variation:
      - k<sub>threshold</sub>
      - k<sub>boc</sub>
      - ...
  - Fuel depletion mobilisation:
    - recipe 
    - Depletion
- Time steps[month]: [1 .. 24]

## Do to

### Simple calculation

#### Problem 1
- 1 PWR UOX
- 1 enrichment factory
Calculation length: 1 reactor cycle

|-------------+----------------------+--------------------+--------+-----+-----|
|     Input   |                      |         Unit       | Values |     |     |
|             |                      |                    +--------+-----+-----|
|             |                      |                    |  1     |  2  |  3  |
|:-----------:|:--------------------:|:------------------:|:------:|:---:|:---:|
|             | P<sub>spec-eff</sub> |  GW/t<sub>HM</sub> |        |     |     |
|             |        Mass          |     t<sub>HM</sub> |        |     |     |
| Reactor     |        Burnup        | GWd/t<sub>HM</sub> |        |     |     |
|             |   Loading pattern    |                    |        |     |     |
|             |     Loading Time     |                    |        |     |     |
|-------------+----------------------+--------------------+--------+-----+-----|
| Enrichement |   UOX  Enrichment    |    %<sub>w</sub>   |        |     |     |
|             |  Tails  Enrichment   |    %<sub>w</sub>   |        |     |     |
|-------------+----------------------+--------------------+--------+-----+-----|
|             |      Time Step       |                    |        |     |     |
|-------------+----------------------+--------------------+--------+-----+-----|

If the tool has some model capabilities, some of those variables might be
overloaded (for example Burnup-UOX enrichement couple). If possible run without
modeling (all parameters fixed) and with modeling (some parameters determined by
the model). Do the same for decay capabilities, if possible run with and
without, if not run the available options.



#### Problem 2
  - 2 PWR UOX
  - 1 enrichment factory
  - Calculation length: 1 reactor cycle
  - Input variable & Model: see Problem 1

#### Problem 3
  - 2 PWR UOX
    - starting: 0y and 50y
    - life time: 100y
  - 1 enrichment factory
  - 1 storage
  - Calculation length: 100 years
  - Input variable & Model: see Problem 1

#### Problem 4
  - 2 PWR UOX
    - starting: 0y and 50y
    - life time: 60y
  - 1 enrichment factory
  - 1 storage
  - Calculation length: 100 years
  - Input variable & Model: see Problem 1

### Full calculation
  

### Sensitivity Analysis
