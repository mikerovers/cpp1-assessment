#include "pch.h"
#include "ShowMapCommand.h"
#include "Output.h"

ShowMapCommand::ShowMapCommand()
{
}


ShowMapCommand::~ShowMapCommand()
{
}

void ShowMapCommand::Execute(Game* game)
{
	Dungeon* const dungeon = game->GetDungeon();
	Output* const output = game->GetOutput();
	output->ShowMap(dungeon, game->GetCurrentLevel());
}
