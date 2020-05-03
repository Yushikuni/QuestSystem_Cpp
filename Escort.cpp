#include "Escort.h"

template <class T>
Escort<T>::Escort();

template <class T>
Escort<T>::Escort(string typ, bool mainQuest, bool activeQuest, bool beginTravel, string finalDestination)
{
	this->s = typ;
	this->mainQuest = mainQuest;
	this->activeQuest = activeQuest;
	this->beginTravel = beginTravel;
	this->finalDestination = finalDestination;
}
template <class T>
Escort<T>::~Escort()
{
	bool beginTravel = false;
	string finalDestination = "";
}
template <class T>
bool Escort<T>::TravelEnd(bool beginTravel, string finalDestination)
{
	beginTravel = false;
	cout << "You have come to the " << finalDestination << endl;
	return beginTravel;
}
