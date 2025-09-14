#include "pch.h"
#include "GameObject.h"
#include "TasteInteractionType.h"


GameObject::GameObject(string name) : GameElement(name)
{
    this->interactionTypes.push_back(new TasteInteractionType("taste", "lick", "eat"));
    this->interactionTypes.push_back(new TasteInteractionType("touch", "miss", "caress"));
}

GameObject::~GameObject()
{
    for (auto& interactionType : this->interactionTypes) {
        delete interactionType;
    }
}

void GameObject::operator=(const GameObject& other)
{
    this->name = other.name;
    for (auto& interactionType : other.interactionTypes) {
        this->interactionTypes.push_back(interactionType);
    }
}

InteractionTypes* GameObject::getSelectedInteractionTypes(string theInteractionType)
{

    for (auto& interactionType : interactionTypes) {
        if (interactionType->getName() == theInteractionType)
            return interactionType;
    }
    return nullptr;
}

vector<InteractionTypes*> GameObject::getInteractionTypes()
{
    return this->interactionTypes;
}



string GameObject::listInteractionTypes()
{
    return "Look\nOpen\nMove\nTurnOn\nTurnOff\nTaste\nPickUp\nDrop";
}


string GameObject::startInteraction(string theInteractiontype)
{
    return "Interaction started successfully!";
}

string GameObject::listCurrentInteractionOptions()//
{
    return string();
}

string GameObject::setCurrentInteractionOptions(string theOption)//
{
    return string();
}

string GameObject::startCurrentInteraction()
{
    return "Current interaction started!";
}

string GameObject::abortCurrentInteraction()
{
    return "Interaction aborted!";
}
