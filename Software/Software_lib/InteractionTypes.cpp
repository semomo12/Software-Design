#include "pch.h"
#include "InteractionTypes.h"



InteractionTypes::InteractionTypes(string name, string option1, string option2) : name(name)
{
	this->interactionOptions.push_back(option1);
	this->interactionOptions.push_back(option2);
}

string InteractionTypes::getName() const
{
	return this->name;
}

vector<string> InteractionTypes::getInteractionOptions()
{
	return this->interactionOptions;
}
