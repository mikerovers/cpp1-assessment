#pragma once
#include "Monster.h"
#include "MonsterHolder.h"
#include <regex>
#include "Game.h"

class MonsterFileParser
{
public:
	explicit MonsterFileParser();
	void parse(const char path[], MonsterHolder* monsterHolder, Game* game);
private:
	Monster* parseMonster(const char m[]);
	std::regex mRegex;
};
