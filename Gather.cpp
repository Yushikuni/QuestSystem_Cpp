#include "Gather.h"

template <class T>
Gather<T>::Gather();

template <class T>
Gather<T>::Gather(string typ, bool mainQuest, bool activeQuest, string nameThing, int howMuchNeed, int howMuchHave)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->active = activeQuest;
	this->nameThing = nameThing;
	this->howMuchNeed = howMuchNeed;
	this->howMuchHave = howMuchHave;
}
template <class T>
Gather<T>::~Gather()
{
	this->s = "";
	this->mainQuest = false;
	this->active = false;
	this->nameThing = "";
	this->howMuchNeed = -1;
	this->howMuchHave = 0;
}
template <class T>
bool Gather<T>::comleteGather(bool uHaveIt, int howMuchHave, int howMuchNeed)
{
	if (howMuchHave == howMuchNeed)
	{
		uHaveIt = true;
	}
	else
	{
		cout << "you still need: " << howMuchNeed - howMuchNeed << " x";
	}
	if (uHaveIt)
	{
		cout << "you have it :D";
	}
}
