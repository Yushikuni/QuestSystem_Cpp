#pragma once
#include <string>
#include <iostream>

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

	// Metoda pro výpis statusu
	virtual void printQuestStatus()
	{
		std::cout << "Quest Status: type, " << this->s
				  << " | Is Main Quest? " << this->mainQuest
				  << " | Is Active Quest? " << this->activeQuest << "\n";
	}
	// how to delete quest? maybee set in to default variable?
	virtual ~QuestSystem() {};
};
