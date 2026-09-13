#include "Delivery.h"

Delivery::Delivery(std::string typ, bool mainQuest, bool activeQuest, std::string packageName) : QuestSystem(typ, mainQuest, activeQuest)
{
	this->packageName = packageName;
}

bool Delivery::CompleteDelivery()
{
	bool done = this->hasPackage;
	if (done)
	{
		std::cout << "Packet was deliver to destination " << this->packageName << "\n";
		this->MarkCompleted();
	}
	return done;
}

void Delivery::PickUpPackage()
{
	this->hasPackage = true;
}