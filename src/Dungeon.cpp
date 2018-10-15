#include "pch.h"
#include "Dungeon.h"
#include "room.h"

// TODO random generation
Dungeon::Dungeon(int width, int height) {
	_width = width;
	_height = height;
}

Dungeon::~Dungeon() {
	for (int h = 0; h < _height; h++)
	{
		delete[] _grid[h];
	}
	delete[] _grid;
	//delete _height, _width;
}

class Room** Dungeon::GetGrid() {
	return _grid;
}

int Dungeon::GetWidth() {
	return _width;
}

int Dungeon::GetHeight() {
	return _height;
}

void Dungeon::GenerateGrid()
{
	_grid = new Room*[_height]; 
	for (int h = 0; h < _height; h++) {
		_grid[h] = new Room[_width];
	}
	SetNeighbours();
}

void Dungeon::SetNeighbours() 
{
	for (int h = 0; h < _height; h++) {
		for (int w = 0; w < _width; w++)
		{
			_grid[h][w].SetNorthNeighbour(h < (_height - 1) ? &_grid[h + 1][w] : nullptr); // + 1
			_grid[h][w].SetEastNeighbour(w < (_width - 1) ? &_grid[h][w + 1] : nullptr); // + 1
			_grid[h][w].SetSouthNeighbour(h > 0 ? &_grid[h - 1][w] : nullptr); // - 1
			_grid[h][w].SetWestNeighbour(w > 0 ? &_grid[h][w - 1] : nullptr); // - 1
		}
	}
}


