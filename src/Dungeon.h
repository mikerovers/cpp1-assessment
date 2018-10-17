#pragma once
#include <iostream>
class Dungeon {
private:
	class BaseRoom*** _levels;
	int _height;
	int _width;
	int _depth;
public:
	Dungeon(int const width, int const height, int const depth);
	~Dungeon();
	void GenerateGrid();
	void SetNeighbours();
	void AddPlayer() const;
	void AddStairs() const;
	void AddEndBoss() const;
	class BaseRoom** GetGrid(int const level) const;
	int GetHeight() const;
	int GetWidth() const;
};