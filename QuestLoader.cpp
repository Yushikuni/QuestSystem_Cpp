#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include "QuestLoader.h"
#include "Kill.h"
#include "Delivery.h"
#include "Escort.h"
#include "Gather.h"

std::vector<std::unique_ptr<QuestSystem>> QuestLoader::LoadFromCSV(const std::string &path)
{
    std::vector<std::unique_ptr<QuestSystem>> quests;
    std::ifstream file(path);
    std::string line;
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "Nelze otevrit soubor: " << path << "\n";
        return quests;
    }

    while (std::getline(file, line))
    {
        std::vector<std::string> tokens = SplitCSVLine(line, ',');
        std::unique_ptr<QuestSystem> quest = CreateQuestFromTokens(tokens);
        if (quest != nullptr)
        {
            quests.push_back(std::move(quest));
        }
        else
        {
            std::cerr << "Varovani: preskocen neplatny CSV radek: " << line << "\n";
        }
    }

    return quests;
}

std::vector<std::string> QuestLoader::SplitCSVLine(const std::string &line, char delim)
{
    std::vector<std::string> tokens; // sem budeme skládat výsledek
    std::stringstream ss(line);      // "obalí" string, aby se z něj dalo číst jako ze souboru
    std::string token;               // dočasná proměnná na jeden kousek

    while (std::getline(ss, token, delim))
    {
        tokens.push_back(token);
    }
    return tokens;
}

static std::optional<int> ParseInt(const std::string &text)
{
    try
    {
        std::size_t pos = 0;
        int value = std::stoi(text, &pos);

        if (pos != text.size()) // stoi nepřečetla celý řetězec
            return std::nullopt;

        return value;
    }
    catch (const std::invalid_argument &)
    {
        return std::nullopt;
    }
    catch (const std::out_of_range &)
    {
        return std::nullopt;
    }
}

std::unique_ptr<QuestSystem> QuestLoader::CreateQuestFromTokens(const std::vector<std::string> &tokens)
{
    if (tokens.empty() || tokens.size() < 5)
    {
        return nullptr;
    }
    if (tokens[0] == "kill")
    {
        if (tokens.size() < 5)
            return nullptr;

        bool mainQuest = (tokens[2] == "1");
        bool activeQuest = (tokens[3] == "1");

        auto kills = ParseInt(tokens[4]); // try/catch + stoi
        if (!kills || *kills <= 0)
            return nullptr;

        return std::make_unique<Kill>(tokens[1], mainQuest, activeQuest, *kills);
    }
    if (tokens[0] == "escort")
    {
        if (tokens.size() < 6)
        {
            return nullptr;
        }
        bool mainQuest = (tokens[2] == "1");
        bool activeQuest = (tokens[3] == "1");
        bool beginTravel = (tokens[4] == "1");
        return std::make_unique<Escort>(tokens[1], mainQuest, activeQuest, beginTravel, tokens[5]);
    }
    if (tokens[0] == "delivery")
    {
        if (tokens.size() < 5)
            return nullptr;

        bool mainQuest = (tokens[2] == "1");
        bool activeQuest = (tokens[3] == "1");
        return std::make_unique<Delivery>(tokens[1], mainQuest, activeQuest, tokens[4]);
    }
    if (tokens[0] == "gather")
    {
        if (tokens.size() < 6)
            return nullptr;

        bool mainQuest = (tokens[2] == "1");
        bool activeQuest = (tokens[3] == "1");

        auto howMuchNeed = ParseInt(tokens[5]);
        if (!howMuchNeed || *howMuchNeed <= 0)
            return nullptr;

        return std::make_unique<Gather>(tokens[1], mainQuest, activeQuest, tokens[4], *howMuchNeed);
    }
    return nullptr;
}
