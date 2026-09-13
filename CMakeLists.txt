cmake_minimum_required(VERSION 3.10)
project(QuestSystem_Cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(QuestSystem_Cpp
    Test_01.cpp
    TestQuestLoader.cpp
    QuestLoader.cpp
    QuestSystem.cpp
    Kill.cpp
    Delivery.cpp
    Escort.cpp
    Gather.cpp
)