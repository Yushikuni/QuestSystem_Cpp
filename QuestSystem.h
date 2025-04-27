#pragma once
#include <iostream>
using namespace std;

template <typename T>
class QuestSystem
{
protected:
	string s;
	bool mainQuest = false;
	bool activeQuest = false;
public:
	//inicialization with two metods, for E0291 solved problem, add QusetSystem();
	QuestSystem();
	//name of quest in string 0(zero) for side quest and unactive, 1(one) for main quest line and active	
	QuestSystem(string typ, bool mainQuest, bool activeQuest);
	//how to delete quest? maybee set in to default variable? 
	~QuestSystem();
};

