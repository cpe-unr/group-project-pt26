# CS 202 Semester Project 

### Group Members and Responsibilities
|**Kayleigh Dohm**|**Drake Lemon**|**Nicole Siron**|
|-----------------|---------------|----------------|
|User Interaction |Modify Metadata|   File Input   |
|   File Output   |All Processors |                |
|    Makefile     |               |                |

### Description of Design
* We created multiple classes to handle separate functions and operations.
* File Input and File Output are their own separate classes that do not need access to each other
* We created a user interaction class that gives the user the option to choose what they want to do (process, metadata, CSV)
* There are two different classes, MonoWav and StereoWav, that handle those respective audio files and each will have a template that allows for either 8 bits or 16 bits so that multiple methods aren't needed for each.
* An interface, Iprocessable, will provide the methods needed for Echo, Normalization, and NoiseGate. Each will override the pure virtual function for their own use.

#### UML Diagrams
![image](https://user-images.githubusercontent.com/77075352/116946356-c2b44800-ac2e-11eb-9fbe-83e5e0b812c8.png)
![image](https://user-images.githubusercontent.com/77075352/116946394-d9f33580-ac2e-11eb-8b8a-11601c6c07f8.png)

### Challenges Encountered
* Communication was difficult just because the class isn't really in person like previous semesters
* Splitting up things to do/ knowing what classes need access to each other
* Bringing all the files back together after they've all been coded
