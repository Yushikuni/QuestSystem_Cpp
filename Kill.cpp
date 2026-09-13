#include "Kill.h"

Kill::Kill(std::string typ, bool mainQuest, bool activeQuest, int requiredKills) : QuestSystem(typ, mainQuest, activeQuest)
{
	this->requiredKills = requiredKills;
}

bool Kill::CompleteSlayer()
{
	bool done = (this->currentKills >= this->requiredKills);
	if (done)
	{
		this->MarkCompleted();
	}
	return done;
}
void Kill::AddKill()
{
	this->currentKills++;
}