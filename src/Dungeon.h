#pragma once
#include <iostream>
class Dungeon {
private:
	class Room** _grid;
	class Room*** _levels;
	int _height;
	int _width;
	int _depth;
public:
	Dungeon(int const width, int const height, int const depth);
	~Dungeon();
	void GenerateGrid();
	void SetNeighbours();
	class Room** GetGrid(int const level);
	int GetHeight();
	int GetWidth();
};