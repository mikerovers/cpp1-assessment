#include "pch.h"
#include "Game.h"
#include "DungeonBuilder.h"
#include "Output.h"

void Game::init()
{
	_output = new Output();
	DungeonBuilder *builder = new DungeonBuilder();
	_dungeon = builder->BuildDungeon(10, 10);
	_output->ShowMap(_dungeon);
}

Game::Game()
{

}

Game::~Game()
{
	delete _dungeon;
}
