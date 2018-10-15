#pragma once
#include <iostream>
class Dungeon {
private:
	class Room** _grid;
	int _height;
	int _width;
public:
	Dungeon(const int width, const int height);
	~Dungeon();
	void GenerateGrid();
	void SetNeighbours();
	class Room** GetGrid();
	int GetHeight();
	int GetWidth();
};