#include "Gather.h"
Gather::Gather(std::string typ, bool mainQuest, bool activeQuest, std::string nameThing, int howMuchNeed)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
	this->nameThing = nameThing;
	this->howMuchNeed = howMuchNeed;
}
bool Gather::completeGather(bool howMuchDoYouHave, int howMuchNeed)
{
	return (howMuchNeed == howMuchDoYouHave);
}
