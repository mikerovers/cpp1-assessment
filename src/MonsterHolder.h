#pragma once
#include "Monster.h";

class MonsterHolder
{
private:
	Monster** _monsters;
public:
	MonsterHolder();
	~MonsterHolder();

	void Init();
	void AddMonster(Monster* monster, int index);
	class Monster** GetMonsters();
};

