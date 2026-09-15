# Software Development Life Cycle (SDLC) 
1-what is sdlc why we need it </p>
2- sdlc phase</p>
3-sdlc model</p>
 1. what are the catagory</p>
 2. what are the model</p>
 </p>
1-what is sdlc why we need it </p>

if we dont have a system these might happen :</p>
* 2 might do the same task this is called chaos. </p>
* misunderstanding of the task or project or the team. </p>
* delay because they dont follow a plan. </p>
* bugs can show because there is no system.</p>

__sdlc definition__
sdlc stand for Software Development Life Cycle
it is a frame work or process to build software system correctly .</p>
* history </p>
in the 60, they used to have idea try to code a solve its bug that was called ad.hoc </p>
and over budget showed up there was also delay or fail because there was no system to work on thats how structed development showed.</p>
in the 70, wintson made water fall model where Winston said that it only work with a certain type of project only because it might fail if used with other projects.</p>

why we need it ?</p>
|without sdlc |with sdlc| 
|-------------|---------|
|1- multiworkflow </p>2-no documentation as a reference</p>3- bugs</p>4-complex maintaince </p>           |1-one workflow</p>2-quality code because there will be document</p>3-tracking for the workflow</p>|

2- sdlc phase</p>
graph TD;

```mermaid
graph TD;
  A["the cycle"]-->B["definition and planning"];
  B-->C["require analysis"];
  C-->D["design"];
  D-->E["code"];
  E-->F["testing"];
  F-->G["deployment"];
  G-->H["maintains"];
```
1-definition and planning //do this in differnet way
you have an idea it make a project over view for it then you start planning if you want to do it or no 
and if the budget and resorce are ok then a project over view is done .</p>we do definition for what we need to know about the product we have 3 name for the product maker he can be business analyst ,product owner ,require engineer then you get output called customer requirement specification for short __"CRS"__ this folder go to chef engineer and he see if this project can be done by hardware or software if we used software we git something from it called __"SRS"__ software requirement specification if hardware"HRS" hardware requirement specification .</p>

2-requirement analysis </p>

|team lead S.W|team lead H.W|team lead testing|
|-------------|-------------|-----------------|
|they take the SRS,HRS,CRS folder| they take the SRS,HRS,CRS folder|they take the SRS,HRS,CRS folder              | 
* reject requirement reasons 
1- no enough experience </p>
2- requirement cancel each other </p>
3- no environment tool for testing </p>
* after rejection 
you go to chef engineer if he have solution good if no they ask the client to understand from him then you get a new CRS,SRS and analysis.</p>
*requirement type //not with the phase it is a tip & trick
                          
 1. function requirement is: what do the system do </p>
 2. non function requirement is: system  quality ,performance and safety.</p>

3- Design</p>
1. high level design "HLD" consist of system design</p>
2. low level design consists of model and architecture </p>
1.1. system design"HLD" make the final structure that consist of :</p>
1.1.1. final component
1.1.2. version

2.2.1. architecture design:
2.2.1.1. static tell us type of layer, software components, API's and description of what i want .</p> 
2.2.1.2. dynamic tell us the memory usage ,execution time ,RTOS .</p>

* module design "flow chart"
flow chart came from language called UML "unified modeling language"
 UML consist of flowchart ,action diagram, state machine, class diagram 

__design out put HLS,LLD,UML diagrams.__

4-Implementation</p>
 here we do coding for the whole system </p>
the output is the code.</p>

5-Validation or testing</p>

1-testing level
 1. unit test  is to test small unit of code ,function, some of the lines.
2. integration test :make sure that every communication work.
3. system test : try the whole system in real environment .
4. acceptance test : see if the system and the requirement are the same.
//interview question
* verification : is are we building the product right
meaning does the requirement match the design match the code.
* validation : is are we building the right product ?
here we make sure that the system match the client requirement .

6- Deployment and maintains
deployment :mean flashing the firmware to the ECU </p>
maintains is bug fixing meaning production bug 

* documentation for each phase 
1-definition and planning 
1. project characteristics in here you define the objectives ,general scope, project over view.</p>
2. project plan contain timeline ,budget, resources.</p>
3. CRS "customer requirement specification" it need client confirmation.</p>

2-require analysis 
1. SRS "software requirement specification".</p>
2. HRS "hardwre requirement specification".</p>

3-design
1. HLD"high level design".</p>
2. SDD "software design document".</p>
3. LLD "low level design".</p>
4. UML digrame.</p>

4-code
1. source code documentation :the comment on the code and the comment type is doxygen style .</p>
2. API's documentation :it explain what actually happens.</p>

5-testing
1. test plan : test strategy meaning what will be test ,who will test ,the tool used in the test .</p>
2. test cases :details steps of the cases.</p>
3.bug/test report.</p>

6-deployment
1. deployment plan:plan on how to publish your system.</p>
2. release note :file that explain the new features and solved bug.</p>
3.user manual .</p>

7-maintains
1. issue log :file that track all the issues like when they should up.</p>
2.change request :file with new features.</p>
