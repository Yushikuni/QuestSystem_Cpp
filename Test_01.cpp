#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include "QuestLoader.h"
#include "TestQuestLoader.h"

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    RunAllQuestLoaderTests();

    std::cout << "--- QUEST SYSTEM START ---" << std::endl;

    auto quests = QuestLoader::LoadFromCSV("quests.csv");
    for (const auto &q : quests)
    {
        q->printQuestStatus();
    }

    std::cout << "\n--- KONEC PROGRAMU ---" << std::endl;
    std::cin.get();

    return 0;
}