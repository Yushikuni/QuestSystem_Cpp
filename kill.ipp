// Kill.ipp
#include <string>
#include <iostream>
#include "Kill.h"

// 2. Opravený parametrický konstruktor (ukládá sumDeath)[cite: 1]
template <class T>
Kill<T>::Kill(std::string typ, bool mainQuest, bool activeQuest, int sumDead, int uSlay, int &slayer) : QuestSystem<T>(typ, mainQuest, activeQuest)
{
    this->sumDeath = sumDead; // TEĎ už si pamatujeme, že máme zabít 10 krys![cite: 1]
    slayer = ++uSlay;
}

// 4. Metoda na vyhodnocení questu
template <class T>
bool Kill<T>::CompleteSlayer(int sumDeath, int &slayer)
{
    return (slayer == sumDeath);
}