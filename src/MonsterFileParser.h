#pragma once
#include "Monster.h"
#include "MonsterHolder.h"
#include <regex>

class MonsterFileParser
{
public:
	explicit MonsterFileParser();
	void parse(const char path[], MonsterHolder* monsterHolder);
private:
	Monster* parseMonster(const char m[]);
	std::regex mRegex;
};