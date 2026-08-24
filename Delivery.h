#pragma once
#include "QuestSystem.h"

class Delivery : public QuestSystem
{
protected:
	bool sthToDeliv = false;
	std::string nameThing = "";

public:
	// inicialization
	Delivery() {};
	Delivery(std::string typ, bool mainQuest, bool activeQuest, std::string nameThing, bool sthToDeliv);
	// destroy
	~Delivery() {};
	// delivery complete
	bool CompleteDelivery(bool &sthToDeliv);
};
