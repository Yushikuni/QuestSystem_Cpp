#pragma once
#include "QuestSystem.h"

template<class T>
class Delivery : public QuestSystem<T>
{
protected:
	bool sthToDeliv = false;
	string nameThing = "";
public:
	//inicialization
	Delivery();
	Delivery(string typ, bool mainQuest, bool activeQuest, string nameThing, bool sthToDeliv);
	//destroy
	~Delivery();
	//delivery complete
	bool CompleteDelivery(bool& sthToDeliv);
};

