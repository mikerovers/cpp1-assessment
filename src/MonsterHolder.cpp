#include "pch.h"
#include "MonsterHolder.h"


MonsterHolder::MonsterHolder()
{
	Init();
}


MonsterHolder::~MonsterHolder()
{
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
