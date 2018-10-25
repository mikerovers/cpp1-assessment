#include "pch.h"
#include "BaseRoom.h"
#include "RandomGenerator.h"
#include "ContentTranslator.h"
#include <iostream>


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


BaseRoom::BaseRoom()
{
	//std::cout << GetDescription();
}


BaseRoom::~BaseRoom()
{

	//delete _description;
	if (_description) {
		delete[] _description;
	}

	_description = nullptr;
	delete _player;
}

char BaseRoom::GetDisplayValue()
{
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
