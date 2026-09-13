#pragma once
#include "QuestSystem.h"

class Delivery : public QuestSystem
{
protected:
	bool hasPackage = false;
	std::string packageName = "";

public:
	// inicialization
	Delivery() {};
	Delivery(std::string typ, bool mainQuest, bool activeQuest, std::string packageName);
	// destroy
	~Delivery() {};
	// delivery complete
	bool CompleteDelivery();
	void PickUpPackage();
};