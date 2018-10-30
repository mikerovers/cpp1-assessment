#include "pch.h"
#include "Dungeon.h"
#include "NormalRoom.h"
#include "StartRoom.h"
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

class BaseRoom**  Dungeon::GetGrid(int const level) const {
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


void Dungeon::SetRoomCharacteristics()
{
	for (int d = 0; d < _depth; d++) {
		for (int h = 0; h < _height; h++) {
			for (int w = 0; w < _width; w++)
			{
				setNeighbours(d, h, w);
				setMonsterLevel(d, h, w);
			}
		}
	}
}

void Dungeon::AddDescription() const {
	for (int d = 0; d < _depth; d++) {
		for (int h = 0; h < _height; h++) {
			for (int w = 0; w < _width; w++)
			{
				_levels[d][h][w].SetRandomContent();
			}
		}
	}
}

void Dungeon::setNeighbours(int const d, int const h, int const w)
{
	_levels[d][h][w].SetNorthNeighbour(h > 0 ? &_levels[d][h - 1][w] : nullptr); // + 1
	_levels[d][h][w].SetEastNeighbour(w < (_width - 1) ? &_levels[d][h][w + 1] : nullptr); // + 1
	_levels[d][h][w].SetSouthNeighbour(h < (_height - 1) ? &_levels[d][h + 1][w] : nullptr); // - 1
	_levels[d][h][w].SetWestNeighbour(w > 0 ? &_levels[d][h][w - 1] : nullptr); // - 1
}

void Dungeon::setMonsterLevel(int const d, int const h, int const w)
{

	if (_depth >= 2 && _depth < 5) // too small to calculate
	{
		if (d == 0) { // highest level
			_levels[d][h][w].SetMonsterLevels(7, 9);
		}
		else if (d == _depth - 1) {// first level
			_levels[d][h][w].SetMonsterLevels(1, 3);
		}
		else { // in between
			_levels[d][h][w].SetMonsterLevels(4, 8);
		}
	}
	else {
		double const a = (d + 1);
		double const b = (_depth + 1);
		int const c = a / b * 8;
		int minLevel = 8 - c;
		if (minLevel < 1) {
			minLevel = 1;
		}
		int const maxLevel = minLevel + 2;
		_levels[d][h][w].SetMonsterLevels(minLevel, maxLevel);
	}
}

void Dungeon::AddPlayer(Player* const player) const {
	RandomGenerator* const random = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) RandomGenerator();
	int width = random->Generate(0, _width - 1);
	int height = random->Generate(0, _height - 1);
	delete random;
	BaseRoom* const room = &_levels[_depth - 1][height][width];
	_levels[_depth - 1][height][width] = StartRoom();
	_levels[_depth - 1][height][width].SetVisited();
	_levels[_depth - 1][height][width].SetPlayer(player);
	player->SetCurrentRoom(&_levels[_depth - 1][height][width]);
}

void Dungeon::AddStairs() const {
	if (_depth <= 1) {
		return;
	}

	RandomGenerator* const random = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) RandomGenerator();
	int widthLastUp, heightLastUp;
	for (int d = 0; d < _depth; d++) {
		int width, height;
		while (true) {
			width = random->Generate(0, _width - 1);
			height = random->Generate(0, _height - 1);
			if (_levels[d][height][width].GetValue() == 'N') {
				break;
			}
		}

		if (d < _depth - 1) {
			_levels[d][height][width].SetUpStairsRoom(&_levels[d + 1][height][width]);
			_levels[d + 1][height][width].SetDownStairsRoom(&_levels[d][height][width]);

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
	RandomGenerator* const random = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) RandomGenerator();
	int width, height;

	while (true) {
		width = random->Generate(0, _width - 1);
		height = random->Generate(0, _height - 1);
		if (_levels[0][height][width].GetValue() == 'N') {
			break;
		}
	}
	delete random;
	_levels[0][height][width] = EndBossRoom();
}


