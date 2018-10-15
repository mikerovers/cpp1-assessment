#include "pch.h"
#include "ShowMapCommand.h"


ShowMapCommand::ShowMapCommand()
{
}


ShowMapCommand::~ShowMapCommand()
{
}

void ShowMapCommand::Execute(Game* game)
{
	Dungeon* dungeon = game->GetDungeon();
	Output* output = game->GetOutput();
	output->ShowMap(dungeon, game->GetCurrentLevel());
}