#include <iostream>
#include "Exception/FileNotOpenedException.h"
#include "File/MonsterFileParser.h"

int main()
{
    try {
        auto *monsterParser = new MonsterFileParser;
        monsterParser->parse("assets/monsters.txt");

        delete monsterParser;
    } catch (FileNotOpenedException& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}