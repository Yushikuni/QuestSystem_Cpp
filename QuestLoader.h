#pragma once

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include "Kill.h"
#include "Delivery.h"
#include "Escort.h"
#include "Gather.h"
#include "QuestSystem.h"

class QuestLoader
{
public:
    static std::vector<std::unique_ptr<QuestSystem>> LoadFromCSV(const std::string &path);

    static std::vector<std::string> SplitCSVLine(const std::string &line, char delim);
    static std::unique_ptr<QuestSystem> CreateQuestFromTokens(const std::vector<std::string> &tokens);
};