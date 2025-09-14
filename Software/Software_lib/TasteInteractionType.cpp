#include "pch.h"
#include "TasteInteractionType.h"

TasteInteractionType::TasteInteractionType(string name, string option1, string option2) : InteractionTypes(name, option1, option2)
{

}

string TasteInteractionType::getSpecificOption(string name)
{
    for (auto& option : this->getInteractionOptions())
        if (option == name)
            return option;
    return "Did not find";
}
