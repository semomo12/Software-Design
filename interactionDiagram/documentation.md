# Documentation Interaction Diagram
Assignment, Interaction Diagram (interact with objects)

This assignment is based on generating interaction diagrams for the system events. 
Create one interaction diagram each for:
selectObject(theGameObjectName)
selectInteraction(theInteractionType)
setInteractionOptions(theOptions)
startInteraction()


We who have worked on this assignment are: 
Gabriel Höglund, Malte Eriksson, Arvid Lindqvist och Seyed Mostafa Mohseni. 
As a tool we have used PlantUML diagrams. 
Our diagram represents the sequence of interactions between different components in a system when a game object is selected. 
PlantUML is a tool that allows us to create UML diagrams from simple text descriptions.

## Small Note
We assume all game element available in the scene has already been created. Overall we have tried thinking along high cohesion and low coupling and balancing them. Also we choose not to write out the use of Polymorfism, but it 
is clearly used for specifying behaviour of for example different GameObjects.

### SelectObject(theGameObjectName)
The first sequence diagram:
selectObject(theGameObjectName)
The classes in this sequence diagram are:
* :Game
* :Scene 
* :ElementHandler 
* :GameObject 
  
This diagram effectively illustrates the flow of method calls and participant activation/deactivation during the process of selecting a game object and retrieving its interaction options.

![SelectObject](.images/selectObject.png)


Our idea and interpretaion of the given use case SelectObject, starts with a call to the Game by the controller pattern. 
Game in turn calls same function to the current active scene as it is the information expert on all available game elements, this including game object. 

From scene it deligates the task of retrieving the selectedObject to the ElementHandler which handles the storage of GameElement by a getFunction and scene stores it in a variable. This is approach uses the indirection pattern and pure fabrication as it is not part of the domain model. 

On the retrieved object we ask to get a list of interaction types belonging to the GameObject through the creator pattern and therefore is the information expert on its available interaction types. 

This list is returned then to the user inferface by means we just assume gets dealt with (by our lovely secretary which we know from the program description).


### SelectInteraction(theInteractionType)
The second sequence diagram:
selectInteraction(theInteractionType)
The classes in this sequence diagram are:

* :Game 
* :Scene 
* :GameObject
* :InteractionType
  
This diagram effectively illustrates the flow of method calls and participant activation/deactivation during the process of selecting an interaction type and retrieving its options.


![SelectObject](.images/selectInteraction.png)


Agian the function call selectInteraction() is directed to the Game as it is the controller for this use case since it is the first interaction with the UI. 

From the Game same as before, we ask the current active scene to get the InteractionType from the previously selectedGameObject because as we said before is the information expert. 

Then, on the selectedInteractionType we request to get the specific options it has, because it is the information expert on its available interaction options. This list is then returned to the UI.



### SetInteractionOption(theOption)
The third sequence diagram:
setInteractionOptions(theOptions)
The classes in this sequence diagram are:

* :Game 
* :Scene
* :InteractionType

This diagram effectively illustrates the flow of method calls and participant activation/deactivation during the process of setting interaction options.

![SelectObject](.images/setInteractionOptions.png)

Once more, to everyones surprise we get a call to Game following the controller pattern.

From it deligate the task to the current active Scene as it is the information expert. 

The scene has the previosly selected interaction type and is therefore qualified to pass the selected option to the interactionType.





### StartInteraction
The fourth sequence diagram:
startInteraction()
The classes in this sequence diagram are:
* :Scene 
* :EventHandler 
* :Event
* :StateHandler

This diagram effectively illustrates the flow of method calls and participant activation/deactivation during the process of starting an interaction and managing 
its results.

![SelectObject](.images/startInteraction.png)

In this event, as it does not take calls from the UI but happens internally from some unknown internal source, 
we make the controller for the usecase to scene, since we think it holds the most information in order to begin executing the interaction (this because it has the selectedInteraction). 

We decided that for an interaction to happen there needs to be a event. Therfore we
decided Scene should deligate the task to an EventHandler by indirection also by pure fabrication since its created by our beautiful imagination. 

The event handler is tasked with handling events and creating them following the creator pattern. 

It initiates the event and during the event it may update the state of things within the game, by interacting with a magical StateHandler who is information expert on these types of assignments using indirection.



