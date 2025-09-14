#include "pch.h"
#include "GameElement.h"

GameElement::GameElement(string name) : name(name)
{
}

string GameElement::getName()
{
    return this->name;
}

