#include "pch.h"
#include "Game.h"
#include "InteractionTypes.h"

Game::Game() : currentScene(new Scene("testScene"))
{
}

Game::~Game()
{
    delete this->currentScene;
}



vector<InteractionTypes*> Game::selectGameObject(string name)
{
     this->selectedGameObject = this->currentScene->selectGameObject(name);
     if (selectedGameObject != nullptr)
         return selectedGameObject->getInteractionTypes();

     return {nullptr};
}

vector<string> Game::selectInteraction(string theInteraction)
{
    this->selectedInteraction = this->selectedGameObject->getSelectedInteractionTypes(theInteraction);
    if (selectedInteraction != nullptr)
        return selectedInteraction->getInteractionOptions();
   
     return {""};
}



string Game::setInteractionOptions(string theOption)
{
    this->selectedOption = selectedInteraction->getSpecificOption(theOption);
    if (selectedOption != "Did not find")
        return "Option is selected";
    return "Option not available";
}

string Game::startInteraction()
{
    return "Started Interaction " + this->selectedInteraction->getName() + " On " + this->selectedGameObject->getName() + " With Option " + selectedOption;
}

string Game::abortInteraction(GameObject gameObject)
{
    return gameObject.abortCurrentInteraction();
}

bool Game::addGameObject(string name)
{
    return this->myGameObjects.addToRepository(name);
}
