#pragma once
#include <iostream>
class Dungeon {
private:
	class BaseRoom** _grid;
	class BaseRoom*** _levels;
	int _height;
	int _width;
	int _depth;
public:
	Dungeon(int const width, int const height, int const depth);
	~Dungeon();
	void GenerateGrid();
	void SetNeighbours();
	void AddPlayer();
	void AddSpecialRooms();
	class BaseRoom** GetGrid(int const level);
	int GetHeight();
	int GetWidth();
};