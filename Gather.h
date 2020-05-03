#pragma once
#include "QuestSystem.h"

template<class T>
class Gather : public QuestSystem<T>
{
protected:
	string s = NULL, nameThing = NULL;
	bool mainQuest = -1, active = -1, uHaveIt = -1;
	int howMuchNeed = -1, howMuchHave = 0;
public:
	//inicializacition
	Gather();
	Gather(string typ, bool mainQuest, bool activeQuest, string nameThing, int howMuchNeed, int howMuchHave);
	//destroyer
	~Gather();
	//sum of something
	bool comleteGather(bool uHaveIt, int howMuchHave, int howMuchNeed);
};

