#include "QuestSystem.h"

//inicialization
template <class T>
QuestSystem<T>::QuestSystem();

template <class T>
QuestSystem<T>::QuestSystem(string typ, bool mainQuest, bool activeQuest)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
}
//destroyer
template <class T>
QuestSystem<T>::~QuestSystem()
{
	this->s = "";
	this->mainQuest = false;
	this->activeQuest = false;
}