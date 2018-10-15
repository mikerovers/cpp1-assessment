#include "pch.h"
#include "BaseRoom.h"


BaseRoom::BaseRoom()
{
	_displayValue = '.';
}


BaseRoom::~BaseRoom()
{
}

char BaseRoom::GetDisplayValue()
{
	if (_hasPlayer) {
		return 'S';
	}
	return _displayValue;
}

bool BaseRoom::HasPlayer()
{
	return _hasPlayer;
}

void BaseRoom::SetHasPlayer(bool hasPlayer)
{
	_hasPlayer = hasPlayer;
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
