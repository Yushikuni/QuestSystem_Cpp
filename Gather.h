#pragma once
#include "QuestSystem.h"

class Gather : public QuestSystem
{
protected:
	std::string s = "", nameThing = "";
	int howMuchNeed = 0, howMuchHave = 0;

public:
	// inicializacition
	Gather(){};
	Gather(std::string typ, bool mainQuest, bool activeQuest, std::string nameThing, int howMuchNeed, int howMuchHave);
	// destroyer
	~Gather() {};
	// sum of something
	bool completeGather(bool uHaveIt, int howMuchHave, int howMuchNeed);
};
