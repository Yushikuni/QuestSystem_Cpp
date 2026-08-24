#include "Kill.h"

Kill::Kill(std::string typ, bool mainQuest, bool activeQuest, int sumDead, int uSlay, int &slayer) : QuestSystem(typ, mainQuest, activeQuest)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
	slayer = ++uSlay;
	this->sumDeath = sumDead;
}

bool Kill::CompleteSlayer(int sumDeath, int &slayer)
{
	return (slayer == sumDeath);
}