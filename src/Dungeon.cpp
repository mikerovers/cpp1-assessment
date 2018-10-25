#include "pch.h"
#include "Dungeon.h"
#include "NormalRoom.h"
#include "DownStaircaseRoom.h"
#include "UpStaircaseRoom.h"
#include "EndBossRoom.h"
#include "StartRoom.h"
#include "RandomGenerator.h"
#include "Player.h"

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
		delete[] _levels[d];
	}
	delete[] _levels;
}

class BaseRoom** Dungeon::GetGrid(int const level) const {
	return _levels[level];
}

int Dungeon::GetWidth() const {
	return _width;
}

int Dungeon::GetHeight() const {
	return _height;
}

void Dungeon::GenerateGrid()
{
	_levels = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) BaseRoom**[_depth];
	for (int d = 0; d < _depth; d++) {
		_levels[d] = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) BaseRoom*[_height];
		for (int h = 0; h < _height; h++) {
			_levels[d][h] = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) NormalRoom[_width];
		}
	}
}


void Dungeon::SetNeighbours()
{
	for (int d = 0; d < _depth; d++) {
		for (int h = 0; h < _height; h++) {
			for (int w = 0; w < _width; w++)
			{
				_levels[d][h][w].SetNorthNeighbour(h < (_height - 1) ? &_levels[d][h + 1][w] : nullptr); // + 1
				_levels[d][h][w].SetEastNeighbour(w < (_width - 1) ? &_levels[d][h][w + 1] : nullptr); // + 1
				_levels[d][h][w].SetSouthNeighbour(h > 0 ? &_levels[d][h - 1][w] : nullptr); // - 1
				_levels[d][h][w].SetWestNeighbour(w > 0 ? &_levels[d][h][w - 1] : nullptr); // - 1
			}
		}
	}
}

void Dungeon::AddPlayer(Player* player) const {
	RandomGenerator* random = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) RandomGenerator();
	int width = random->Generate(0, _width - 1);
	int height = random->Generate(0, _height - 1);
	delete random;
	BaseRoom* room = &_levels[_depth - 1][height][width];
	_levels[_depth - 1][height][width] = StartRoom();
	_levels[_depth - 1][height][width].SetVisited();
	_levels[_depth - 1][height][width].SetPlayer(player);
	player->SetCurrentRoom(&_levels[_depth - 1][height][width]);
}

void Dungeon::AddStairs() const {
	if (_depth <= 1) {
		return;
	}

	RandomGenerator* random = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) RandomGenerator();
	int widthLastUp, heightLastUp;
	for (int d = 0; d < _depth; d++) {
		int width, height;
		while (true) {
			width = random->Generate(0, _width - 1);
			height = random->Generate(0, _height - 1);
			if (typeid(_levels[d][height][width]) == typeid(BaseRoom)) {
				break;
			}
		}

		if (d == 0) {//only stairs up
			widthLastUp = width;
			heightLastUp = height;
			_levels[d][height][width] = UpStaircaseRoom();
		}
		else if (d == _depth - 1) {// only stairs down
			_levels[d][heightLastUp][widthLastUp] = DownStaircaseRoom();
		}
		else { // both up and down
			_levels[d][heightLastUp][widthLastUp] = DownStaircaseRoom();
			widthLastUp = width;
			heightLastUp = height;
			_levels[d][height][width] = UpStaircaseRoom();
		}
	}
	delete random;
}

void Dungeon::AddEndBoss() const {
	RandomGenerator* random = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) RandomGenerator();
	int width, height;

	while (true) {
		width = random->Generate(0, _width - 1);
		height = random->Generate(0, _height - 1);
		if (typeid(_levels[0][height][width]) == typeid(BaseRoom)) {
			break;
		}
	}
	delete random;
	_levels[0][height][width] = EndBossRoom();
}


