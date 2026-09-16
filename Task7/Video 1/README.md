# Part 1 Summary: [Complete Guide to Software Engineering Phases]

## Software Development LifeCycle (SDLC)
* Definition: It's a framework or process to build software system correctly.
---
* Why needed? without it, there are struggles with: inaccurately_estimated budgets, complex maintennce for the program, multi workflows(one by each developer/contributor), no documentation as a reference of the client's requirements, many bugs and the unability of tracking which lead to delays.
---
# Phases: 
1. Definition & Planning -> through which the client gives the idea to the (business analyst/product owner/requirement engineer)so that he has the Customer Requirement Specification(CRS). The CRS is analyzed by the Chief Engineer who produces the Software Requirement Specification(SRS) and the Hardware Requirement Specification(HRS).
---
2. Requirement Analysis -> Through which The team leaders of hardware, software and testing review the SRS, the HRS, and maybe the CRS (to make sure the chief engineer)missed nothing.

.Requirement Rejection Reasons:
- No enough Experience 
- opposition of a requirement to another 
- No tool/environment to test. 

              (Rejected requirements-> chief engineer -> client = CRS -> SRS -> Analysis) 
---
.Requirement types:
- Functional Requirement : what the system does
- Non-Functional Requirement : regarding safety, quality & performance 
---
3. Design-> Divided into :
```
│
├── High level design(System Design): where the final structure is designed 
│      
│      
│      
│
├── Low level design: 
                    │
                    ├── Architecture design: 
                    │                      |
                    |                      ├── Static (Layered Architecture,APIs,SWC,Description)
                    |                      │      
                    |                      |      
                    |                      │ 
                    |                      ├── Dynamic (Memory usage, Execution Time)
                    │      
                    │      
                    │      
                    │ 
                    ├── Model design: Unified Modeling Language (UML)


  ```  
                                      (Output: HLD, LLD &UML Diagrams)
---
4. Implementation-> Coding of the whole system
---
5. Validation/Testing ->
Testing levels : 
                 
                 1) Unit test :for functions or some code lines

                 2) Integration test : tests the inner communication of modules 
                 (making sure dashboard deals with backend as expected)

                 3) System test : Done at the level of the company

                 4) Acceptance test : Done wiht the client 

* Verification: verifies whether the requirements match the design and whether the code matched the design 
(was the project built in a right way?) 
* Validation : validates whether the system matches the product needed by the client.
(is what was built the right product?)
---
6. Deployment & Maintenance -> Fixing Production Bugs 
---




<div align="center">

**Built by: Malak Mohammed**

















