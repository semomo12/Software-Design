#pragma once
#include "InteractionTypes.h"
class TouchInteractionType : public InteractionTypes
{
private:


public:
	TouchInteractionType() = default;
	TouchInteractionType(string name, string option1, string option2);
	virtual string getSpecificOption(string name) override;
};

