// Test_01.cpp : Tento soubor obsahuje funkci main.
//
#include <WinNls.h>
#include <consoleapi2.h>
#include "QuestLoader.h"
#include "TestQuestLoader.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

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