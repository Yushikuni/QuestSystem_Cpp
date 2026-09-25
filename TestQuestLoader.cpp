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

void TestKillCompletion()
{
    Kill quest("Zabij krysy", true, true, 3); // requiredKills = 3

    assert(quest.IsCompleted() == false); // na začátku není hotovo

    quest.AddKill();
    quest.AddKill();
    assert(quest.CompleteSlayer() == false); // 2 z 3, ještě ne

    quest.AddKill();
    assert(quest.CompleteSlayer() == true); // 3 z 3, hotovo
    assert(quest.IsCompleted() == true);    // a base flag to potvrzuje
}

void TestGatherCompletion()
{
    Gather quest("Sesbírej mi pár bylinek", true, true, "Valštovičník", 2);
    assert(quest.IsCompleted() == false);
    quest.AddGathered(1);
    assert(quest.IsCompleted() == false);
    quest.AddGathered(1);
    assert(quest.CompleteGather() == true);
    assert(quest.IsCompleted() == true);
}

void TestDeliveryCompletiotion()
{
    Delivery quest("Dones balík", true, true, "Krabice");
    assert(quest.IsCompleted() == false);
    quest.PickUpPackage();
    quest.CompleteDelivery();
    assert(quest.CompleteDelivery());
    assert(quest.IsCompleted() == true);
}

void TestEscortCompletiotion()
{
    Escort quest("Escort", true, true, true, "Gauč");
    assert(quest.IsCompleted() == false);
    quest.TravelEnd();
    assert(quest.IsCompleted() == true);
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
    TestKillCompletion();

    TestGatherCompletion();
    TestDeliveryCompletiotion();
    TestEscortCompletiotion();

    std::cout
        << "Vsechny testy prosly!\n";
}