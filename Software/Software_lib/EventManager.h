#pragma once
#include "Header.h"


class EventManager {
private:
	vector<string> events;
public:
	void createEvent(string EventCondition, string Event);
	string listAffectedEvents(string EventCondition);
	void triggerEvents(string EventCondition);
	void clearEvent(string EventCondition);

};
