#pragma once
#include "Header.h"

class GameElement {
public:
	string name;
	GameElement() = default;
	GameElement(string name);
	string getName();


	//string createEvent(string eventCondition, string event);
	//string	clearEvent(string event);
};