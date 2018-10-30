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
#include "Helmet.h"
#include "Shoes.h"

void BaseRoom::SetRandomContent()
{
	RandomGenerator* const random = new (_NORMAL_BLOCK, __FILE__, __LINE__) RandomGenerator();
	int const roomSize = random->Generate(0, 2);
	int const tidyness = random->Generate(0, 1);
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
		_item = new (_NORMAL_BLOCK, __FILE__, __LINE__) Potion();
	}
	else if (chance < 30) {
		_item = new (_NORMAL_BLOCK, __FILE__, __LINE__) Shoes();
	}
	else if (chance < 40) {
		_item = new (_NORMAL_BLOCK, __FILE__, __LINE__) Helmet();
	}
	else if (chance < 50) {
		_item = new (_NORMAL_BLOCK, __FILE__, __LINE__) BroadSword();
	}
	else if (chance < 60) {
		_item = new (_NORMAL_BLOCK, __FILE__, __LINE__) Shield();
	}
	else {
		_item = nullptr;
	}
	delete random;
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
	//delete _monster;
	if (_item) {
		delete _item;
	}

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

void BaseRoom::RemoveItem() {
	_item = nullptr;
}

void BaseRoom::SetMonsterLevels(int min, int max)
{
	_minMonsterLevel = min;
	_maxMonsterLevel = max;
}

void BaseRoom::PlayerEnters(MonsterHolder * const monsterHolder, BaseRoom* const lastRoom)
{
	Output* const output = new (_NORMAL_BLOCK, __FILE__, __LINE__) Output();

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
}

char BaseRoom::GetDisplayValue()
{

	if (_player != nullptr) {
		return 'P';
	}
	if (_visited == 0) {
		return '.';
	}
	return _displayValue;
}

char BaseRoom::GetValue() {
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
