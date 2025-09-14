#include "pch.h"
#include "TouchInteractionType.h"

TouchInteractionType::TouchInteractionType(string name, string option1, string option2) : InteractionTypes(name, option1, option2)
{
}

string TouchInteractionType::getSpecificOption(string name)
{
    for (auto& option : this->getInteractionOptions())
        if (option == name)
            return option;
    return "Did not find";
}
