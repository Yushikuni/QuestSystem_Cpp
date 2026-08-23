#include "Gather.h"
Gather::Gather(std::string typ, bool mainQuest, bool activeQuest, std::string nameThing, int howMuchNeed, int howMuchHave)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->active = activeQuest;
	this->nameThing = nameThing;
	this->howMuchNeed = howMuchNeed;
	this->howMuchHave = howMuchHave;
}
bool Gather::comleteGather(bool uHaveIt, int howMuchHave, int howMuchNeed)
{
	return (howMuchHave == howMuchNeed);
}
