#include "Kill.h"

Kill::Kill(std::string typ, bool mainQuest, bool activeQuest, int requiredKills) : QuestSystem(typ, mainQuest, activeQuest)
{
	this->requiredKills = requiredKills;
}

void Kill::AddKill()
{
	this->currentKills++;
}
bool Kill::CompleteQuest()
{
	bool done = (this->currentKills >= this->requiredKills);
	if (done)
	{
		this->MarkCompleted();
	}
	return done;
}