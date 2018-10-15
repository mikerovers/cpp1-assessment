#include "pch.h"
#include "Dungeon.h"
#include "NormalRoom.h"
#include "RandomGenerator.h"

// TODO random generation
Dungeon::Dungeon(int const width, int const height, int const depth) {
	_width = width;
	_height = height;
	_depth = depth;
}

Dungeon::~Dungeon() {
	for (int d = 0; d < _depth; d++) {
		for (int h = 0; h < _height; h++)
		{
			delete[] _levels[d][h];
		}
		delete _levels[d];
	}
	delete[] _grid;
}

class BaseRoom** Dungeon::GetGrid(int const level) {
	return _levels[level];
}

int Dungeon::GetWidth() {
	return _width;
}

int Dungeon::GetHeight() {
	return _height;
}

void Dungeon::GenerateGrid()
{
	_levels = new BaseRoom**[_depth];
	for (int d = 0; d < _depth; d++) {
		_grid = new BaseRoom*[_height];
		for (int h = 0; h < _height; h++) {
			_grid[h] = new BaseRoom[_width];
		}
		_levels[d] = _grid;
	}
}


void Dungeon::SetNeighbours()
{
	for (int d = 0; d < _depth; d++) {
		for (int h = 0; h < _height; h++) {
			for (int w = 0; w < _width; w++)
			{
				_grid[h][w].SetNorthNeighbour(h < (_height - 1) ? &_levels[d][h + 1][w] : nullptr); // + 1
				_grid[h][w].SetEastNeighbour(w < (_width - 1) ? &_levels[d][h][w + 1] : nullptr); // + 1
				_grid[h][w].SetSouthNeighbour(h > 0 ? &_levels[d][h - 1][w] : nullptr); // - 1
				_grid[h][w].SetWestNeighbour(w > 0 ? &_levels[d][h][w - 1] : nullptr); // - 1
			}
		}
	}
}

void Dungeon::AddPlayer() {
	RandomGenerator* random = new RandomGenerator();
	int width = random->Generate(1, _width);
	int height = random->Generate(1, _height);
	_levels[0][height][width].SetHasPlayer(true);
	//std::cout << width << std::endl;
	//std::cout << height << std::endl;
}

void Dungeon::AddSpecialRooms() {
	Dungeon::AddPlayer();
}



