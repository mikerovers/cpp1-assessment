#ifndef CPP1_ASSESSMENT_FILEPARSER_H
#define CPP1_ASSESSMENT_FILEPARSER_H

#include <fstream>
#include <iostream>
#include <regex>
#include "../Monster.h"
#include "../MonsterList.h"

class MonsterFileParser
{
public:
    explicit MonsterFileParser();
    Monster* parse(const char path[]);
private:
    Monster* parseMonster(const char m[]);
    std::regex mRegex;
};


#endif //CPP1_ASSESSMENT_FILEPARSER_H
