#include "MonsterFileParser.h"
#include "FileReader.h"
#include "../Exception/FileNotOpenedException.h"
#include "../Exception/MonsterParsingException.h"

const int MAXLINE = 256;

void MonsterFileParser::parse(const char path[])
{
    auto *reader = new FileReader();

    try {
        auto monsterFile = reader->openFile(path);
        delete reader;

        char oneLine[MAXLINE];
        while (monsterFile) {
            monsterFile.getline(oneLine, MAXLINE);

            parseMonster(oneLine);
        }

        monsterFile.close();
    } catch (FileNotOpenedException e) {

    } catch (MonsterParsingException e) {

    }
}

Monster* MonsterFileParser::parseMonster(const char m[])
{
    std::cmatch matches;

    if (std::regex_search(m, matches, mRegex)) {
        auto* monster = new Monster();

        try {
            char* name = const_cast<char*>(matches[1].str().c_str());

            monster->setName(name);
            monster->setLevel(static_cast<unsigned int>(atoi(matches[2].str().c_str())));
            monster->setAttackChance(static_cast<unsigned int>(atoi(matches[3].str().c_str())));
            monster->setAttacksPerRound(static_cast<unsigned int>(atoi(matches[4].str().c_str())));
            monster->setMinAmountOfDamage(static_cast<unsigned int>(atoi(matches[5].str().c_str())));
            monster->setMaxAmountOfDamage(static_cast<unsigned int>(atoi(matches[6].str().c_str())));
            monster->setEvasionChance(static_cast<unsigned int>(atoi(matches[7].str().c_str())));
            monster->setHP(static_cast<unsigned int>(atoi(matches[8].str().c_str())));

            return monster;
        } catch (int e) {
            throw MonsterParsingException();
        }
    } else {
        return nullptr;
    }
}

MonsterFileParser::MonsterFileParser()
{
    mRegex = (R"(\[([a-z ]+);([\d]+|BAAS);(\d+)x(\d);(\d+)-(\d+);(\d+);(\d+)\])");
}
