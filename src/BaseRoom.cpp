#include "pch.h"
#include "BaseRoom.h"
#include "Output.h"
#include "RandomGenerator.h"

void BaseRoom::setMonster(MonsterHolder* monsterHolder)
{
	RandomGenerator* random = new (_NORMAL_BLOCK, __FILE__, __LINE__) RandomGenerator();
	int chance = random->Generate(1, 100);
	if (chance >= 50) {
		_monster = monsterHolder->GetRandomMonsterByLevelRange(_minMonsterLevel, _maxMonsterLevel);
	}
	else {
		_monster = nullptr;
	}
	delete random;
}

void BaseRoom::setItem()
{
}

BaseRoom::BaseRoom()
{
}


BaseRoom::~BaseRoom()
{
	delete _player;
}

BaseRoom & BaseRoom::operator=(const BaseRoom & other)
{
	if (this != &other) {

	}

	return *this;
}

Monster * BaseRoom::GetMonster()
{
	return _monster;
}

Item * BaseRoom::GetItem()
{
	return _item;
}

void BaseRoom::SetMonsterLevels(int min, int max)
{
	_minMonsterLevel = min;
	_maxMonsterLevel = max;
}

void BaseRoom::PlayerEnters(MonsterHolder* monsterHolder)
{
	setMonster(monsterHolder);
	Output* output = new Output();
	output->ClearScreen();
	output->ShowRoomDescription(this);
	output->BlankLine();
	output->ShowExits(this);
	output->BlankLine();
	output->ShowEnemies(_monster);
	output->BlankLine();
	output->ShowOptions();
	delete output; 
}

void BaseRoom::PlayerLeaves() {
	_player = nullptr;
	_monster = nullptr;
}

char BaseRoom::GetDisplayValue()
{
	if (BaseRoom::GetPlayer()) {
		return 'S';
	}
	if (!_visited) {
		return '.';
	}
	return _displayValue;
}

void BaseRoom::SetVisited()
{
	_visited = true;
}

void BaseRoom::SetPlayer(Player* player) {
	_player = player;
}

Player* BaseRoom::GetPlayer()
{
	return _player;
}

BaseRoom * BaseRoom::GetNorthNeighbour()
{
	return _northNeighBour;
}

void BaseRoom::SetNorthNeighbour(BaseRoom * room)
{
	_northNeighBour = room;
}

BaseRoom * BaseRoom::GetEastNeighbour()
{
	return _eastNeighBour;
}

void BaseRoom::SetEastNeighbour(BaseRoom * room)
{
	_eastNeighBour = room;
}

BaseRoom * BaseRoom::GetSouthNeighbour()
{
	return _southNeighBour;
}

void BaseRoom::SetSouthNeighbour(BaseRoom * room)
{
	_southNeighBour = room;
}

BaseRoom * BaseRoom::GetWestNeighbour()
{
	return _westNeighBour;
}

void BaseRoom::SetWestNeighbour(BaseRoom * room)
{
	_westNeighBour = room;
}
