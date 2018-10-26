#include "pch.h"
#include "BaseRoom.h"
#include <cstring>
#include "Output.h"

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

void BaseRoom::PlayerEnters()
{
	Output* output = new Output();

	output->ShowRoomDescription(this);
	delete output;
	// TODO 
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
