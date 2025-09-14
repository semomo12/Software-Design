#pragma once
#include "Header.h"
#include "GameElement.h"
#include "InteractionTypes.h"
class GameObject : public GameElement {
	vector <InteractionTypes*> interactionTypes;
public:
	GameObject() = default;
	GameObject(string name);
	~GameObject();
	void operator = (const GameObject& other);
	
	InteractionTypes* getSelectedInteractionTypes(string theInteractionType);
	vector<InteractionTypes*> getInteractionTypes();



	// Additions ...
	string listInteractionTypes();
	string startInteraction(string theInteractiontype);
	string listCurrentInteractionOptions();
	string setCurrentInteractionOptions(string theOption);
	string startCurrentInteraction();
	string abortCurrentInteraction();
};