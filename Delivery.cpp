#include "Delivery.h"


template <class T>
Delivery<T>::Delivery();

template <class T>
Delivery<T>::Delivery(string typ, bool mainQuest, bool activeQuest, string nameThing, bool sthToDeliv)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
	this->nameThing = nameThing;
	this->sthToDeliv = sthToDeliv;
}
template <class T>
Delivery<T>::~Delivery()
{
	bool sthToDeliv = false;
	string nameThing = "";
}

//metod retun boolean :D
template <class T>
bool Delivery<T>::CompleteDelivery(bool& sthToDeliv)
{
	sthToDeliv = false;
	cout << "Packet was deliver to destination " << this->nameThing << endl;
	return sthToDeliv;
}