# Video 2 – SDLC: Documentation per Phase & SDLC Models

**Video:** https://www.youtube.com/watch?v=EzXBZbH1DzE

## 1. Documentation Produced in Each Phase

### 1) Definition & Planning
- **Project Charter** – objectives, general scope, project overview
- **Project Plan** – timeline, budget, resources
- **CRS** – Customer Requirement Specification (needs confirmation from the client)

### 2) Requirement Analysis
- **SRS** – Software Requirement Specification
- **HRS** – Hardware Requirement Specification

### 3) Design
- **HLD** – High Level Design
- **SDD** – Software Design Documentation
- **LLD** – Low Level Design
- **UML Diagrams**

### 4) Coding
- **Source Code Documentation** – comments in the code (Doxygen style)
- **API Documentation**

### 5) Testing
- **Test Plan** – strategy for testing: what will be tested and who tests it
- **Test Cases**
- **Bug Report / Test Report**

### 6) Deployment
- Deployment Plan
- Release Notes
- User Manual

### 7) Maintenance
- Issue Log
- Change Request

## 2. SDLC Models

### Waterfall Model
- Introduced in the 1970s by Winston Royce
- Sequential model

**Phases**
1. Requirements (Definition, Planning, Requirement Analysis)
2. Design (HLD, LLD)
3. Implementation (Coding)
4. Verification (Testing & Deployment)
5. Maintenance

**Problems**
1. Doesn't accept requirement changes/edits
2. No early testing (a rejected requirement is only caught once testing tools/environments are ready)
3. Customer is not involved throughout the life cycle

**Advantages**
1. Easy to use and understand
2. Easy to manage
3. Sequential process with clear deliverables for each phase

**When to use**
- Simple projects
- Short-term projects
- Reliable / good customer

### V-Model
**Steps**
1. Requirement
2. System Design
3. Software Design
4. Module Design
5. Coding
6. Unit Test
7. Integration Test
8. System Test
9. Acceptance Test

**Advantages (compared to Waterfall)**
1. Early testing – test planning starts alongside design
2. Faster than Waterfall

**Still shares some Waterfall limitations**
- Customer not heavily involved during development
- Doesn't easily support requirement changes

**When to use**
1. Simple project
2. Good / reliable customer
3. Fast delivery requirement
