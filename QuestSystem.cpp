#include "QuestSystem.h"

//inicialization
QuestSystem::QuestSystem();
QuestSystem::QuestSystem(string typ, bool mainQuest, bool activeQuest)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
}
void QuestSystem::printQuestStatus()
{
    // Tady by byl kód pro výpis statusu
    std::cout << "Quest Status: type," << this->s << " is Main Quest? " << this->mainQuest << " is Active Quest? " << this->activeQuest;
}