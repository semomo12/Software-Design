#pragma once
#include "Header.h"

class InteractionTypes
{
private:
	string name;
	vector<string> interactionOptions;
public:
	InteractionTypes() = default;
	InteractionTypes(string name, string option1, string option2);
	virtual ~InteractionTypes() = default;
	string getName() const;
	vector<string> getInteractionOptions();
	virtual string getSpecificOption(string name) = 0;
};


