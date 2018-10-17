#pragma once
#include "Player.h"
class DungeonBuilder {
public:
	DungeonBuilder();
	~DungeonBuilder();
	class Dungeon* BuildDungeon(Player* player, int const width, int const height, int const depth) const;
};