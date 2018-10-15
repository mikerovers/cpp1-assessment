#include "pch.h"
#include "DungeonBuilder.h"
#include "Dungeon.h"

DungeonBuilder::DungeonBuilder() {

}

DungeonBuilder::~DungeonBuilder() {

}

Dungeon* DungeonBuilder::BuildDungeon(int const width, int const height) {
	Dungeon* dungeon = new Dungeon(width, height);
	dungeon->GenerateGrid();
	dungeon->SetNeighbours();
	return dungeon;
}