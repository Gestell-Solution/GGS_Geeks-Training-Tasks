/**
 * @file Agile.md
 * @brief This file contains the best points between Water fall model & V_model .
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/17/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
 */

# 🚀Software Development Life Cycle (SDLC) Models

## 📑 Table of Contents
1. Waterfall Model
- Overview & History
- Phases Breakdown
- Advantages & Disadvantages
- When to Use
2. V-Model (Verification & Validation)
- Overview
- Phase Mapping & Structure
- Advantages & Disadvantages
3. Waterfall vs. V-Model Comparison

---

# 1. Waterfall Model
**Overview & History**
Introduced in: 1970
Pioneered by: Winston W. Royce
Model Type: Sequential / Linear Model
The Waterfall Model is a classic linear sequential software development life cycle. Each phase must be completed fully before the next phase begins, with no overlapping between phases.
Phases Breakdown
1. **Requirement Analysis**📋:
- Defines the system requirements.
- Project planning and initial definition.
2. **Design** 🎨:
- High-Level Design (HLD): System Architecture.
- Low-Level Design (LLD): Detailed Module Design.
3. **Implementation**💻:
- Actual coding and implementation of designed architecture.
4. **Testing (Verification) & Deployment**✅:
- Verifying system against requirements and deploying to production.
5. **Maintenance**🔧:
- Ongoing post-release updates, bug fixes, and system enhancements.


## **Advantages & Disadvantages:
### ✅Advantages
🟢 Easy to understand and use.
🟢 Easy to manage due to its rigid structure.
🟢 Sequential ,Deliverables for each phase 
### ❌Disadvantages / Problems
🔴 Customer is not involved during the main development lifecycle.
🔴 Does not accept requirement changes or edits late in the lifecycle.
🔴 No early testing — bugs discovered late are costly to fix.

### When to Use
- Simple & Easy Project 
- Short Term
- Good Customer 

---
##### 2. V-Model (Verification & Validation)
**Detailed Mapping List:**
1. Requirement Phase ➔ Acceptance Testing: Ensures requirements meet customer expectations.
2. System Design Phase ➔ System Testing: Validates overall system behavior and architecture.
3. Software Design Phase ➔ Integration Testing: Tests communication between modules/services.
4. Module Design Phase ➔ Unit Testing: Tests individual components/functions.
5. Coding: The base execution step connecting design and testing.


##### Advantages & Disadvantages

# ✅Advantages
🟢 Early Testing: Test plans are designed during development phases.
🟢 Faster & higher quality delivery compared to standard Waterfall.
# ❌Disadvantages / Problems
🔴 Customer is not involved during active implementation.
🔴 Does not support requirement changes midway through execution.

---

## When to Use V_Model**
- Simple Project
- Good Customer
- Fast Delivery Reguirment

---

### 3. Waterfall vs. V-Model Comparison
Feature
Waterfall Model
V-Model
Testing Strategy
Testing happens after coding
Testing planned parallel to design
Flexibility
Rigid, no late edits
Rigid, planned test coverage
Defect Detection
Late in the lifecycle
Early in the lifecycle
Best Suited For
Simple, well-defined projects
Mission-critical, high-reliability projects

----------------------------------------------------------------------------------------------------------------------