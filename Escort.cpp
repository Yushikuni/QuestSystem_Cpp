#include "Escort.h"

Escort::Escort(std::string typ, bool mainQuest, bool activeQuest, bool beginTravel, std::string finalDestination)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
	this->beginTravel = beginTravel;
	this->finalDestination = finalDestination;
}

bool Escort::TravelEnd(bool beginTravel, std::string finalDestination)
{
	this->beginTravel = false;
	std::cout << "You have come to the " << finalDestination << "\n";
	return this->beginTravel;
}
