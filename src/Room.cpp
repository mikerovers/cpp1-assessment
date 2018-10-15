#include "pch.h"
#include "Room.h"

Room::Room() {
	_displayValue = 3;
}

char Room::GetDisplayValue() {
	return _displayValue;
}

void Room::SetDisplayValue(int const value) {
	_displayValue = value;
}

Room* Room::GetNorthNeighbour() {
	return _northNeighBour;
}

void Room::SetNorthNeighbour(Room* const room) {
	_northNeighBour = room;
}

Room* Room::GetEastNeighbour() {
	return _eastNeighBour;
}

void Room::SetEastNeighbour(Room* const room) {
	_eastNeighBour = room;
}

Room* Room::GetSouthNeighbour() {
	return _southNeighBour;
}

void Room::SetSouthNeighbour(Room* const room) {
	_southNeighBour = room;
}

Room* Room::GetWestNeighbour() {
	return _westNeighBour;
}

void Room::SetWestNeighbour(Room* const room) {
	_westNeighBour = room;
}

Room::~Room() {
	delete &_displayValue;
}