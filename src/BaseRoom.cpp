#include "pch.h"
#include "BaseRoom.h"
#include "RandomGenerator.h"
#include "ContentTranslator.h"
#include "Output.h"
#include <iostream>
#include "Item.h"
#include "BroadSword.h"
#include "Potion.h"
#include "Shield.h"


void BaseRoom::SetRandomContent()
{
	RandomGenerator* random = new (_NORMAL_BLOCK, __FILE__, __LINE__) RandomGenerator();
	int roomSize = random->Generate(0, 2);
	int tidyness = random->Generate(0, 1);
	int layout = random->Generate(0, 2);
	delete random;

	ContentTranslator* translator = new (_NORMAL_BLOCK, __FILE__, __LINE__) ContentTranslator();
	_description = translator->GetDescription(roomSize, tidyness, layout);
	delete translator;
}

void BaseRoom::setMonster(MonsterHolder* monsterHolder)
{
	if (_displayValue == 'E') {
		_monster = monsterHolder->GetRandomBoss();
	}
	else {
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
}

void BaseRoom::setItem()
{
	RandomGenerator* random = new (_NORMAL_BLOCK, __FILE__, __LINE__) RandomGenerator();
	int chance = random->Generate(1, 100);
	if (chance < 20) {
		_item = new BroadSword();
	}
	else if (chance < 40) {
		char tmp[15];
		char *temp;
		temp = &tmp[0];
		_item = new Potion(temp);
	}
	else if (chance < 60) {
		_item = new Shield();
	}
	else {
		_item = nullptr;
	}

}

void BaseRoom::SetUpStairsRoom(BaseRoom* room)
{
	_upStairsRoom = room;
}

BaseRoom * BaseRoom::GetUpStairsRoom()
{
	return _upStairsRoom;
}

void BaseRoom::SetDownStairsRoom(BaseRoom* room)
{
	_downStairsRoom = room;
}

BaseRoom * BaseRoom::GetDownStairsRoom()
{
	return _downStairsRoom;
}


BaseRoom::BaseRoom()
{

}


BaseRoom::~BaseRoom()
{
	if (_description) {
		delete[] _description;
	}

	_description = nullptr;
	delete _player;
	delete _monster;
	delete _item;
}

BaseRoom & BaseRoom::operator=(const BaseRoom & other)
{
	if (this != &other) {

		_displayValue = other._displayValue;
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

void BaseRoom::PlayerEnters(MonsterHolder * monsterHolder, BaseRoom* lastRoom)
{
	if (!_visited) {
		setItem();
	}
	if (_upStairsRoom) {
		if (_upStairsRoom != lastRoom) {
			_player->MoveTo(monsterHolder, _upStairsRoom);
		}
	}
	else if (_downStairsRoom) {
		if (_downStairsRoom != lastRoom) {
			_player->MoveTo(monsterHolder, _downStairsRoom);
		}
	}
	setMonster(monsterHolder);
	Output* output = new Output();
	output->ClearScreen();
	output->ShowRoomDescription(this);
	output->BlankLine();
	output->ShowItem(_item);
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
	_item = nullptr;
}

char BaseRoom::GetDisplayValue()
{
	if (_player != nullptr) {
		return 'P';
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

char * BaseRoom::GetDescription()
{
	return _description;
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
