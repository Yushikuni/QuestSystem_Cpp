#pragma once
#include "QuestSystem.h"

class Kill : public QuestSystem
{
protected:
	int sumDeath;

public:
	Kill() {}; // Prázdné tělo přímo v hlavičce

	// Parametrický konstruktor definovaný přímo zde:
	Kill(std::string typ, bool mainQuest, bool activeQuest, int sumDead);
	~Kill() {};

	bool CompleteSlayer(int sumDeath);
};