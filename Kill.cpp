#include "Kill.h"

template <class T>
Kill<T>::Kill();

template <class T>
Kill<T>::Kill(string typ, bool mainQuest, bool activeQuest, int sumDead, int uSlay, int& slayer)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
	slayer = ++uSlay;
}

template <class T>
Kill<T>::~Kill()
{
	int sumDeath = -1;
	int uSlay = 0;
	int slayer = 0;
}

template <class T>
bool Kill<T>::CompleteSlayer(int sumDeath, int& slayer)
{
	bool wat = false;
	if (slayer == sumDeath)
	{
		wat = true;
	}
	else
	{
		wat = false;
	}
	return wat;
}
