#include <iostream>
#include "Exception/FileNotOpenedException.h"
#include "File/MonsterFileParser.h"
#include <iterator>

int main()
{
    try {
        auto *monsterParser = new MonsterFileParser;
        auto* monsters = monsterParser->parse("assets/monsters.txt");

        for (int i = 0; i < 14; ++i) {
            auto monster = &monsters[i];
            std::cout << monsters[i].getName() << "\n";

        }

        delete monsterParser;
    } catch (FileNotOpenedException& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}