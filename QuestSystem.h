#pragma once
#include <string>

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
