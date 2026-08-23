#pragma once
#include "QuestSystem.h"

class Escort : public QuestSystem
{
protected:
	bool beginTravel = false;
	std::string finalDestination = "";
public:
	//inicialization
	Escort();
	Escort(std::string typ, bool mainQuest, bool activeQuest, bool beginTravel, std::string finalDestination);
	//destroyer
	~Escort(){};
	//end of travel
	bool TravelEnd(bool beginTravel,std::string finalDestination);
};

