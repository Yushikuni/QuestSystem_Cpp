#pragma once
#include "QuestSystem.h"

class Escort final : public QuestSystem
{
private:
	bool beginTravel = false;
	std::string finalDestination = "";

public:
	// inicialization
	Escort(std::string typ, bool mainQuest, bool activeQuest, bool beginTravel, std::string finalDestination);
	// end of travel
	bool TravelEnd();
	// destroyer
	~Escort() {};
};