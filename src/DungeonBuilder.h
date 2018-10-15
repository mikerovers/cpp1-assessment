#pragma once
class DungeonBuilder {
public:
	DungeonBuilder();
	~DungeonBuilder();
	class Dungeon* BuildDungeon(int const width, int const height, int const depth);
};