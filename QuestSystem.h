#pragma once
#ifndef QUEST_SYSTEM_H
#define QUEST_SYSTEM_H
#include <string>

template <typename T>
class QuestSystem
{
protected:
	std::string s;
	bool mainQuest = false;
	bool activeQuest = false;

public:
	// inicialization with two metods, for E0291 solved problem, add QusetSystem();
	QuestSystem() {};
	// name of quest in string 0(zero) for side quest and unactive, 1(one) for main quest line and active
	QuestSystem(std::string typ, bool mainQuest, bool activeQuest);

	void printQuestStatus();
	// how to delete quest? maybee set in to default variable?
	virtual ~QuestSystem() {};
};

// !!! KLÍČOVÝ TRIK !!!
// Na úplný konec souboru (před #endif) vložíme implementaci.
#include "QuestSystem.ipp"

#endif // QUEST_SYSTEM_H