#pragma once
#include "QuestSystem.h"

template<class T>
class Escort : public QuestSystem<T>
{
protected:
	bool beginTravel = false;
	string finalDestination = "";
public:
	//inicialization
	Escort();
	Escort(string typ, bool mainQuest, bool activeQuest, bool beginTravel, string finalDestination);
	//destroyer
	~Escort();
	//end of travel
	bool TravelEnd(bool beginTravel,string finalDestination);
};

