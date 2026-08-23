#PRAGMA ONCE

#include "QuestSystem.h"

class Gather : public QuestSystem
{
protected:
	string s = "", nameThing = "";
	bool mainQuest = false, active = false, uHaveIt = false;
	int howMuchNeed = 0, howMuchHave = 0;
public:
	//inicializacition
	Gather();
	Gather(string typ, bool mainQuest, bool activeQuest, string nameThing, int howMuchNeed, int howMuchHave);
	//destroyer
	~Gather(){};
	//sum of something
	bool comleteGather(bool uHaveIt, int howMuchHave, int howMuchNeed);
};

