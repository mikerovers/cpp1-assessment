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

	class Monster** GetMonsters();
	class Monster* GetRandomMonsterByLevelRange(int min, int max);
	class Monster* GetRandomBoss();
};

