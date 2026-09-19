# Video 1 – SDLC: What It Is & Its Phases

**Video:** https://www.youtube.com/watch?v=EvPIdiWUcxQ

## 1. What is SDLC and Why We Need It

**Definition**
SDLC (Software Development Life Cycle) is a framework / process used to build a software system correctly.

**History**
- 1960s → Ad-hoc, unstructured development
- 1970s → Winston Royce introduced the Waterfall Model

**Problems without a defined process**
1. Chaos
2. Misunderstanding
3. Delays
4. Bugs

**Why We Need SDLC**

| Without SDLC | With SDLC |
|---|---|
| Multiple / conflicting workflows | One clear workflow |
| No documentation as reference | Quality code |
| Bugs | Tracking |
| Complex maintenance | |

## 2. SDLC Phases (Deep Dive)

### Phase 1 – Definition & Planning
- Client shares an idea → project overview
- Planning → project charter
- Definition: client works with the product team (Business Analyst, Product Owner, Requirement Engineer)
  - Output: **CRS** – Customer Requirement Specification
  - The Chief Engineer splits the work:
    - Hardware (H.W) → **HRS** (Hardware Requirement Specification)
    - Software (S.W) → **SRS** (Software Requirement Specification)

### Phase 2 – Requirement Analysis
- Involves the H.W Team, S.W Team, and Validation Team
- Each team works from the same SRS, HRS, and CRS
- Team leads (SW / HW / Testing) all reference SRS, HRS, CRS

**Reasons a requirement can be rejected**
1. Not enough experience
2. Requirement conflicts with another requirement
3. No tool/environment available for testing

Rejected requirements go back through the Requirement Engineer to the client for re-analysis.

**Requirement Types**
- **Functional Requirements** – what the system should do
- **Non-Functional Requirements** – performance, quality, and safety

### Phase 3 – Design
- **High Level Design (HLD)** – system design → final structure, final components, versioning
- **Low Level Design (LLD)** – architecture & models

**Architecture Design**
- **Static** – layered architecture (APP, HAL, MCAL), SWC/APIs, component style, pages, index/description
- **Dynamic** – memory usage, execution time, RTOS (tasks, priority, periodicity)

**Module Design (Flowchart) / UML (Unified Modeling Language)**
- Output: HLD, LLD, and UML Diagrams (flowchart/action diagrams, state machines, class diagrams)

### Phase 4 – Implementation
- Coding for the whole system
- Output: source code

### Phase 5 – Validation / Testing
**Testing Levels**
1. Unit Test – tests a small unit of code (a function or a few lines)
2. Integration Test
3. System Test
4. Acceptance Test

- **Verification** – "Are we building the product right?" (Requirement → Design → Code must match)
- **Validation** – "Are we building the right product?" (the system must match what the client actually wanted)

### Phase 6 – Deployment & Maintenance
- **Deployment** – embedding (flashing firmware onto the ECU)
- **Maintenance** – fixing bugs found in production

## Overall SDLC Flow
Definition & Planning → Requirement Analysis → Design → Code → Testing → Deployment → Maintenance
