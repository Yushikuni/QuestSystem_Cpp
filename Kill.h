#pragma once
#include "QuestSystem.h"

class Kill : public QuestSystem
{
protected:
	int requiredKills;
	int currentKills = 0;

public:
	Kill() {}; // Prázdné tělo přímo v hlavičce

	// Parametrický konstruktor definovaný přímo zde:
	Kill(std::string typ, bool mainQuest, bool activeQuest, int requiredKills);
	~Kill() {};

	bool CompleteSlayer();
	void AddKill();
};