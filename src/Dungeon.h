#pragma once
#include <iostream>
#include "Player.h"
class Dungeon {
private:
	class BaseRoom*** _levels;
	int _height;
	int _width;
	int _depth;

	void setNeighbours(int d, int h, int w);
	void setMonsterLevel(int d, int h, int w);
public:
	Dungeon(int const width, int const height, int const depth);
	~Dungeon();
	void GenerateGrid();
	//void SetNeighbours();
	void SetRoomCharacteristics();
	void AddPlayer(Player* player) const;
	void AddStairs() const;
	void AddEndBoss() const;
	class BaseRoom** GetGrid(int const level) const;
	int GetHeight() const;
	int GetWidth() const;
};