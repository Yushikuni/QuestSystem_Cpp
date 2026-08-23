#pragma once
#include "QuestSystem.h"

class Escort : public QuestSystem
{
protected:
	bool beginTravel = false;
	string finalDestination = "";
public:
	//inicialization
	Escort();
	Escort(string typ, bool mainQuest, bool activeQuest, bool beginTravel, string finalDestination);
	//destroyer
	~Escort(){};
	//end of travel
	bool TravelEnd(bool beginTravel,string finalDestination);
};

