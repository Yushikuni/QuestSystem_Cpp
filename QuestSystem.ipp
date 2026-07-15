// QuestSystem.ipp
// (Tento soubor nemá vlastní #include "QuestSystem.h",
// protože je sám vkládán DO QuestSystem.h)
#include <iostream>

template <typename T>
QuestSystem<T>::QuestSystem(std::string typ, bool main, bool active)
{
    this->s = typ;
    this->mainQuest = main;
    this->activeQuest = active;
}
template <typename T>
void QuestSystem<T>::printQuestStatus()
{
    // Tady by byl kód pro výpis statusu
    std::cout << "Quest Status: type," << this->s << " is Main Quest? " << this->mainQuest << " is Active Quest? " << this->activeQuest;
}