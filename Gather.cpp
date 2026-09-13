#include "Gather.h"
Gather::Gather(std::string typ, bool mainQuest, bool activeQuest, std::string resourceName, int howMuchNeed) : QuestSystem(typ, mainQuest, activeQuest)
{
	this->resourceName = resourceName;
	this->howMuchNeed = howMuchNeed;
}
bool Gather::CompleteGather()
{
	bool done = this->howMuchHave >= this->howMuchNeed;
	if (done)
	{
		this->MarkCompleted();
	}
	return done;
}
void Gather::AddGathered(int amount)
{
	this->howMuchHave += amount;
}