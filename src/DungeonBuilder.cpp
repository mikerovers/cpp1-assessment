#include "pch.h"
#include "DungeonBuilder.h"
#include "Dungeon.h"

DungeonBuilder::DungeonBuilder() {

}

DungeonBuilder::~DungeonBuilder() {

}

Dungeon* DungeonBuilder::BuildDungeon(Player* player, int const width, int const height, int const depth) const{
	Dungeon* dungeon = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) Dungeon(width, height, depth);
	dungeon->GenerateGrid();
	dungeon->SetRoomCharacteristics();
	dungeon->AddStairs();
	dungeon->AddEndBoss();
	dungeon->AddDescription();
	dungeon->AddPlayer(player);

	return dungeon;
}