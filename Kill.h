// Kill.h
#ifndef KILL_H
#define KILL_H

#include <string>
#include "QuestSystem.h"

template <typename T>
class Kill : public QuestSystem<T>
{
private:
	int sumDeath = -1;

public:
	Kill() {}; // Prázdné tělo přímo v hlavičce

	// Parametrický konstruktor definovaný přímo zde:
	Kill(std::string typ, bool mainQuest, bool activeQuest, int sumDeath, int uSlay, int &slayer);
	~Kill() {};

	bool CompleteSlayer(int sumDeath, int &slayer);
};

// TENTO ŘÁDEK MUSÍ BÝT PŘESNĚ TAKTO (před #endif):
#include "Kill.ipp"

#endif // KILL_H