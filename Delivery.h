#pragma once
#include "QuestSystem.h"

class Delivery final : public QuestSystem
{
private:
	bool hasPackage = false;
	std::string packageName = "";

public:
	// inicialization
	Delivery(std::string typ, bool mainQuest, bool activeQuest, std::string packageName);
	// destroy
	~Delivery() {};
	// delivery complete
	bool CompleteQuest() override;
	void PickUpPackage();
};