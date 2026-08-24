#include "Delivery.h"

Delivery::Delivery(std::string typ, bool mainQuest, bool activeQuest, std::string nameThing, bool sthToDeliv)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
	this->nameThing = nameThing;
	this->sthToDeliv = sthToDeliv;
}

bool Delivery::CompleteDelivery(bool &sthToDeliv)
{
	sthToDeliv = false;
	std::cout << "Packet was deliver to destination " << this->nameThing << "\n";
	return sthToDeliv;
}