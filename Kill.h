#pragma once
#include "QuestSystem.h"

class Kill : public QuestSystem
{
private:
	int sumDeath = -1;

public:
	Kill() {}; // Prázdné tělo přímo v hlavičce

	// Parametrický konstruktor definovaný přímo zde:
	Kill(std::string typ, bool mainQuest, bool activeQuest, int sumDead, int uSlay, int &slayer);
	~Kill() {};

	bool CompleteSlayer(int sumDeath, int &slayer);
};