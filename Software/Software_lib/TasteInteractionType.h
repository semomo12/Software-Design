#pragma once
#include "InteractionTypes.h"
class TasteInteractionType : public InteractionTypes
{
private:

public:
	TasteInteractionType(string name, string option1, string option2);
	virtual string getSpecificOption(string name) override;
};

