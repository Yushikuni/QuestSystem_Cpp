#include "Delivery.h"

Delivery::Delivery();
Delivery::Delivery(string typ, bool mainQuest, bool activeQuest, string nameThing, bool sthToDeliv)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
	this->nameThing = nameThing;
	this->sthToDeliv = sthToDeliv;
}
Delivery::~Delivery(){}

bool Delivery::CompleteDelivery(bool& sthToDeliv)
{
	sthToDeliv = false;
	cout << "Packet was deliver to destination " << this->nameThing << endl;
	return sthToDeliv;
}