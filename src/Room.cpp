#include "pch.h"
#include "Room.h"
#include "Output.h"

Room::Room() {
	Room::_displayValue = 'N';
}

char Room::GetDisplayValue() {
	return _displayValue;
}

Room* Room::GetNorthNeighbour() {
	return _northNeighBour;
}

void Room::SetNorthNeighbour(Room* const room) {
	Room::_northNeighBour = room;
}

Room* Room::GetEastNeighbour() {
	return _eastNeighBour;
}

void Room::SetEastNeighbour(Room* const room) {
	Room::_eastNeighBour = room;
}

Room* Room::GetSouthNeighbour() {
	return _southNeighBour;
}

void Room::SetSouthNeighbour(Room* const room) {
	Room::_southNeighBour = room;
}

Room* Room::GetWestNeighbour() {
	return _westNeighBour;
}

void Room::SetWestNeighbour(Room* const room) {
	Room::_westNeighBour = room;
}

Room::~Room() {
	delete &_displayValue;
	delete _northNeighBour, _eastNeighBour, _southNeighBour, _westNeighBour;
}