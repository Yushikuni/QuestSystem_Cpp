# QuestSystem_Cpp

![NazevHry](https://user-images.githubusercontent.com/42646031/151656474-d2b754c1-990f-4bef-9a73-ec306c4aeb07.png)

## C++ quest system with data-driven loading

A small C++ portfolio project demonstrating OOP class hierarchy design and
data-driven content loading. Four quest types (`Kill`, `Delivery`, `Escort`,
`Gather`) inherit from a common `QuestSystem` base with virtual dispatch and
shared completion tracking (`MarkCompleted()` / `IsCompleted()`).

Quests are defined in a CSV file and loaded at runtime via `QuestLoader`,
which parses each row, validates the column count and values per quest
type, and constructs the appropriate polymorphic object
(`unique_ptr<QuestSystem>`). Runtime progress (kills, gathered items,
package pickup) is tracked separately from the quest's static definition.

## CSV format

Each row starts with a quest type, followed by shared fields and
type-specific fields:
``` csv
kill,<name>,<mainQuest 0/1>,<activeQuest 0/1>,<requiredKills>
escort,<name>,<mainQuest>,<activeQuest>,<beginTravel 0/1>,<destination>
delivery,<name>,<mainQuest>,<activeQuest>,<packageName>
gather,<name>,<mainQuest>,<activeQuest>,<resourceName>,<requiredAmount>
```

Malformed rows (wrong column count, invalid numbers) are skipped with a
warning, not crashed on.

## Building

Requires a C++17-compatible compiler. Build with CMake:

```bash
cmake -B build
cmake --build build
```

## Testing

Unit tests (edge cases: empty input, unknown quest type, malformed rows,
a regression test for a past name-shadowing bug) live in
`TestQuestLoader.h`/`.cpp` and run automatically on startup via
`RunAllQuestLoaderTests()`