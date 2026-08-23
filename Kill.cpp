#include "Kill.h"
Kill::Kill();
Kill::Kill(string typ, bool mainQuest, bool activeQuest, int sumDead, int uSlay, int& slayer)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
	slayer = ++uSlay;
}
Kill::~Kill()
{
	int sumDeath = -1;
	int uSlay = 0;
	int slayer = 0;
}

bool Kill::CompleteSlayer(int sumDeath, int& slayer)
{
	return (slayer == sumDeath);
}