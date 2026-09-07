// Test_01.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//
#include <cassert>
#include <WinNls.h>
#include <consoleapi2.h>
#include "QuestLoader.h"

void TestCreateQuestFromTokens()
{
    // test 1: prázdný vektor tokenů
    auto result1 = QuestLoader::CreateQuestFromTokens({});
    assert(result1 == nullptr);

    // test 2: neznámý typ
    auto result2 = QuestLoader::CreateQuestFromTokens({"inihalition", "Znic Vesnici", "1", "1", "1"});
    assert(result2 == nullptr);

    // test 3: moc krátký řádek pro "escort"
    auto result3 = QuestLoader::CreateQuestFromTokens({"escort", "Doprovoď pana do hospody", "0", "1"});
    assert(result3 == nullptr);
    // test 4: moc krátký kill quest:
    auto result4 = QuestLoader::CreateQuestFromTokens({"kill", "zabij", ""});
    assert(result4 == nullptr);
    // test 4: špatný kill quest:
    auto resultX = QuestLoader::CreateQuestFromTokens({"kill", "zabij", "", "", ""});
    assert(resultX == nullptr);

    // test 5: moc ktrátké delivery quest:
    auto result5 = QuestLoader::CreateQuestFromTokens({"delivery", "donáška pizzy", "", "", ""});
    assert(result5 == nullptr);
    // test 6: moc ktrátky gather quest:
    auto result6 = QuestLoader::CreateQuestFromTokens({"gather", "sezbírej mi....", "1", "1", "", "", ""});
    assert(result6 == nullptr);

    std::cout << "Vsechny testy prosly!\n";
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    TestCreateQuestFromTokens();
    /*  // Malý testovací výpis, abychom viděli, že program vůbec žije
      std::cout << "--- QUEST SYSTEM START ---" << std::endl;

      auto quests = QuestLoader::LoadFromCSV("quests.csv");
      for (const auto &q : quests)
      {
          q->printQuestStatus();
      }

      std::cout << "\n--- KONEC PROGRAMU ---" << std::endl;

      // Tento řádek donutí konzoli počkat na stisknutí klávesy, než se zavře
      std::cin.get();
  */
    return 0;
}