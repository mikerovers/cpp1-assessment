#pragma once
#include "Monster.h"

class MonsterHolder
{
private:
	Monster** _monsters;
	int _size;
public:
	MonsterHolder(int monsterCount);
	~MonsterHolder();

	void Init();
	void AddMonster(Monster* monster, int index);

	Monster** GetMonsters();
	Monster* GetRandomMonsterByLevelRange(int min, int max);
	Monster* GetRandomBoss();
};

