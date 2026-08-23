#PRAGMA ONCE
#include "Escort.h"

Escort::Escort();


Escort::Escort(string typ, bool mainQuest, bool activeQuest, bool beginTravel, string finalDestination)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
	this->beginTravel = beginTravel;
	this->finalDestination = finalDestination;
}
bool Escort::TravelEnd(bool beginTravel, string finalDestination)
{
	beginTravel = false;
	cout << "You have come to the " << finalDestination << endl;
	return beginTravel;
}
