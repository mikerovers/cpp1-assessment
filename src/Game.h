#pragma once
#include "Dungeon.h"
#include "Room.h"

class Game {
private:
	class Dungeon* _dungeon;
	class Output* _output;
public:
	void init();
	Game();
	~Game();
};