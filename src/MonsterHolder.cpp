#include "pch.h"
#include "MonsterHolder.h"


MonsterHolder::MonsterHolder()
{
	Init();
}


MonsterHolder::~MonsterHolder()
{
	for (int i = 0; i < 14; i++) {
		delete _monsters[i];
	}
	delete _monsters;
}

void MonsterHolder::Init()
{
	_monsters = new Monster*[14];
}

void MonsterHolder::AddMonster(Monster * monster, int index)
{
	_monsters[index] = monster;
}

Monster ** MonsterHolder::GetMonsters()
{
	return _monsters;
}
