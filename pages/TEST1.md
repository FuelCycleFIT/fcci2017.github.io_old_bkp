
Problem 1:
----------


PWR UOX:
````````

#. Simple calculation

#. Full calculation fix parameters

#. Sensitivity analysis




Output var:
  - Unat consumption
  - Pu mass
  - vector Pu
  - MA mass
  - MA vector 
  - PF mass
  - PF vector
  - LCOE 

input var:
  - Reactor:
    - P/M
    - Capacity Factor
    - Cycle Time
    - Burnup
    - Mass
    - laoding patern
    - loading time
  - Enrichment:
    - enrichment tails
    - enrichemnt UOX

Model:
  - decay or not decay in Cycle (not in reactor)
  - Fuel Fab modelisation: 
    - Fix 
    - Loading model
      - model description
        - model generation:
          - depletion tool
          - geometry
          - sampling ?

      - Batching consideration
  - Fuel depletion modelisation:
    - recipe 
    - Depletion
      - model parameter
        - Batching consideration
        - model generation:
          - depletion tool
          - geometry
          - sampling ?
