#include "QuestSystem.h"

QuestSystem::QuestSystem(std::string typ, bool mainQuest, bool activeQuest)
{
	this->stringType = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
}

void QuestSystem::MarkCompleted()
{
	this->completed = true;
}

bool QuestSystem::IsCompleted()
{
	return this->completed;
}