#include "TestQuestLoader.h"
#include "QuestLoader.h"
#include <cassert>
#include <sstream>
#include <iostream>

std::string CaptureOutput(QuestSystem *q)
{
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    q->printQuestStatus();
    std::cout.rdbuf(old);
    return buffer.str();
}

void TestGatherPrintsCorrectName()
{
    auto quest = QuestLoader::CreateQuestFromTokens(
        {"gather", "Sesbirej byliny", "0", "1", "hermanek", "10"});
    assert(quest != nullptr);

    std::string output = CaptureOutput(quest.get());
    assert(output.find("Sesbirej byliny") != std::string::npos);
}

void RunAllQuestLoaderTests()
{
    auto result1 = QuestLoader::CreateQuestFromTokens({});
    assert(result1 == nullptr);

    auto result2 = QuestLoader::CreateQuestFromTokens({"inihalition", "Znic Vesnici", "1", "1", "1"});
    assert(result2 == nullptr);

    auto result3 = QuestLoader::CreateQuestFromTokens({"escort", "Doprovoď pana do hospody", "0", "1"});
    assert(result3 == nullptr);

    auto result4 = QuestLoader::CreateQuestFromTokens({"kill", "zabij", ""});
    assert(result4 == nullptr);

    auto resultX = QuestLoader::CreateQuestFromTokens({"kill", "zabij", "", "", ""});
    assert(resultX == nullptr);

    auto result5 = QuestLoader::CreateQuestFromTokens({"delivery", "donáška pizzy", "1"});
    assert(result5 == nullptr);

    auto result6 = QuestLoader::CreateQuestFromTokens({"gather", "sezbírej mi....", "1", "1", "", "", ""});
    assert(result6 == nullptr);

    TestGatherPrintsCorrectName();

    std::cout << "Vsechny testy prosly!\n";
}