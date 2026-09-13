#pragma once
#include "QuestSystem.h"

class Gather : public QuestSystem
{
protected:
	std::string resourceName;
	int howMuchNeed = 0, howMuchHave = 0;

public:
	// inicializacition
	Gather() {};
	Gather(std::string typ, bool mainQuest, bool activeQuest, std::string resourceName, int howMuchNeed);

	// destroyer
	~Gather() {};
	// sum of something
	bool CompleteGather();
	void AddGathered(int amount);
};
