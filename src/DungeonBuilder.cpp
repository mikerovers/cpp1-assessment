#include "pch.h"
#include "DungeonBuilder.h"
#include "Dungeon.h"

DungeonBuilder::DungeonBuilder() {

}

DungeonBuilder::~DungeonBuilder() {

}

Dungeon* DungeonBuilder::BuildDungeon(Player* player, int const width, int const height, int const depth) const{
	Dungeon* dungeon = new Dungeon(width, height, depth);
	dungeon->GenerateGrid();
	dungeon->SetNeighbours();
	dungeon->AddPlayer(player);
	dungeon->AddStairs();
	dungeon->AddEndBoss();
	return dungeon;
}