#pragma once
#include "QuestSystem.h"

template<class T>
class Kill : public QuestSystem<T>
{
protected:
	int sumDeath = -1;//how much NPCs needed to be dead
	int uSlay = 0;	//how much you slay NPCs
	int slayer = 0;
public:
	//inicialization
	Kill();
	Kill(string typ, bool mainQuest, bool activeQuest, int sumDeath, int uSlay, int& slayer);
	//destroyer
	~Kill();
	//complete quest full of slay the enemy
	bool CompleteSlayer(int sumDeath, int& slayer);
};


