#pragma once
#include <iostream>
#include "Room.h"
#include "Dungeon.h"

class Output {
public:
	Output();
	~Output();
	void ShowMap(Dungeon* dungeon) const;
	void ShowNeighbours(Dungeon* dungeon) const;
};