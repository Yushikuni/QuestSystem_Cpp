#include "Escort.h"

Escort::Escort(std::string typ, bool mainQuest, bool activeQuest, bool beginTravel, std::string finalDestination) : QuestSystem(typ, mainQuest, activeQuest)
{
	this->beginTravel = beginTravel;
	this->finalDestination = finalDestination;
}

bool Escort::TravelEnd()
{
	bool done = this->beginTravel;
	if (done)
	{
		this->beginTravel = false;
		this->MarkCompleted();
	}
	return done;
}