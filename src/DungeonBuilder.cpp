#include "pch.h"
#include "DungeonBuilder.h"
#include "Dungeon.h"

DungeonBuilder::DungeonBuilder() {

}

DungeonBuilder::~DungeonBuilder() {

}

Dungeon* DungeonBuilder::BuildDungeon(int const width, int const height, int const depth) {
	Dungeon* dungeon = new Dungeon(width, height, depth);
	dungeon->GenerateGrid();
	dungeon->SetNeighbours();
	dungeon->AddSpecialRooms();
	return dungeon;
}