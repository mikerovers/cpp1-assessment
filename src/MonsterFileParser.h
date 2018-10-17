#pragma once
#include "Monster.h"
#include <regex>

class MonsterFileParser
{
public:
	explicit MonsterFileParser();
	Monster** parse(const char path[]);
private:
	Monster* parseMonster(const char m[]);
	std::regex mRegex;
};
