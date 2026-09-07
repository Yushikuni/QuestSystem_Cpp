#include "QuestLoader.h"

std::vector<std::unique_ptr<QuestSystem>> QuestLoader::LoadFromCSV(const std::string &path)
{
    std::vector<std::unique_ptr<QuestSystem>> quests;
    std::ifstream file(path);
    std::string line;

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

std::unique_ptr<QuestSystem> QuestLoader::CreateQuestFromTokens(const std::vector<std::string> &tokens)
{
    std::cerr << "DEBUG: pocet tokenu = " << tokens.size() << "\n";
    for (size_t i = 0; i < tokens.size(); i++)
    {
        std::cerr << "  tokens[" << i << "] = '" << tokens[i] << "'\n";
    }
    if (tokens.empty() || tokens.size() < 5)
    {
        return nullptr;
    }
    if (tokens[0] == "kill")
    {
        if (tokens.size() < 5)
            return nullptr;
        try
        {
            bool mainQuest = (tokens[2] == "1");
            bool activeQuest = (tokens[3] == "1");
            int sumDead = std::stoi(tokens[4]);
            int placeholderSlayer = 0;
            return std::make_unique<Kill>(tokens[1], mainQuest, activeQuest, sumDead, 0, placeholderSlayer);
        }
        catch (const std::invalid_argument &)
        {
            return nullptr;
        }
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
        if (tokens.size() < 6)
            return nullptr;
        try
        {
            bool mainQuest = (tokens[2] == "1");
            bool activeQuest = (tokens[3] == "1");
            bool somethingToDeliver = (tokens[5] == "1");
            return std::make_unique<Delivery>(tokens[1], mainQuest, activeQuest, tokens[4], somethingToDeliver);
        }
        catch (const std::invalid_argument &)
        {
            return nullptr;
        }
    }
    if (tokens[0] == "gather")
    {
        if (tokens.size() < 7)
            return nullptr;
        try
        {
            bool mainQuest = (tokens[2] == "1");
            bool activeQuest = (tokens[3] == "1");
            int howMuchNeed = std::stoi(tokens[5]);
            // todo Upravit - jde to na dluh!
            int howMuchHave = std::stoi(tokens[6]);

            return std::make_unique<Gather>(tokens[1], mainQuest, activeQuest, tokens[4], howMuchNeed, howMuchHave);
        }
        catch (const std::invalid_argument &)
        {
            return nullptr;
        }
    }
    return nullptr;
}
