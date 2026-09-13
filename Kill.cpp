#include "Kill.h"

Kill::Kill(std::string typ, bool mainQuest, bool activeQuest, int sumDeath) : QuestSystem(typ, mainQuest, activeQuest)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
	this->sumDeath = sumDeath;
}

bool Kill::CompleteSlayer(int sumDeath)
{
	return true;
}