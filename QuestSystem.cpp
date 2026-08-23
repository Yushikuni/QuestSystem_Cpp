#include "QuestSystem.h"

QuestSystem::QuestSystem(std::string typ, bool mainQuest, bool activeQuest)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
}