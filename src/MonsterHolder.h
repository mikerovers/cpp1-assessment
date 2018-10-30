#pragma once
#include "Monster.h"

class MonsterHolder
{
private:
	Monster** _monsters;
	int _size;
public:
	MonsterHolder(int const monsterCount);
	~MonsterHolder();

	void Init();
	void AddMonster(Monster*const  monster, int const index);

	Monster* const* const GetMonsters();
	Monster* const GetRandomMonsterByLevelRange(int const min, int const max);
	Monster* const GetRandomBoss();
};

