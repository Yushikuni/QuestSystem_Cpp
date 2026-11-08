#pragma once
#include "QuestSystem.h"

class Kill : public QuestSystem
{
protected:
	int requiredKills;
	int currentKills = 0;

public:
	// Parametrický konstruktor definovaný přímo zde:
	Kill(std::string typ, bool mainQuest, bool activeQuest, int requiredKills);
	~Kill() {};

	bool CompleteQuest() override;
	void AddKill();
};