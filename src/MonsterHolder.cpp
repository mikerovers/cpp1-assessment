#include "pch.h"
#include "MonsterHolder.h"
#include "RandomGenerator.h"
#include <iostream>


MonsterHolder::MonsterHolder(int const monsterCount)
{
	_size = monsterCount;
	Init();
}

MonsterHolder::~MonsterHolder()
{
	for (int i = 0; i < 14; i++) {
		if (_monsters[i] != NULL)
		delete _monsters[i];
	}
	delete _monsters;
}

void MonsterHolder::Init()
{
	_monsters = new (_NORMAL_BLOCK, __FILE__, __LINE__) Monster*[14];
}

void MonsterHolder::AddMonster(Monster * const monster, int const index)
{
	_monsters[index] = monster;
}

Monster *const * const MonsterHolder::GetMonsters()
{
	return _monsters;
}

Monster * const MonsterHolder::GetRandomMonsterByLevelRange(int const min, int const max)
{
	Monster* monsters[14];

	int counter = 0;
	for (int i = 1; i < _size; i++) {
		Monster* const monster = _monsters[i];
		int monsterLevel = GetMonsters()[i]->getLevel();
		if (monsterLevel >= min && monsterLevel <= max) {
			monsters[counter] = _monsters[i];
			counter++;
		}
	}

	RandomGenerator* const random = new (_NORMAL_BLOCK, __FILE__, __LINE__) RandomGenerator();
	int chosenIndex = random->Generate(0, counter - 1);
	Monster* monster = monsters[chosenIndex];

	delete random;

	return monster;
}

Monster * const MonsterHolder::GetRandomBoss()
{
	RandomGenerator* const random = new (_NORMAL_BLOCK, __FILE__, __LINE__) RandomGenerator();
	int chosenIndex = random->Generate(12, 13);
	delete random;
	return _monsters[chosenIndex];
}
