#include "Gather.h"
Gather::Gather();
Gather::Gather(string typ, bool mainQuest, bool activeQuest, string nameThing, int howMuchNeed, int howMuchHave)
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
	return(howMuchHave == howMuchNeed)
}
