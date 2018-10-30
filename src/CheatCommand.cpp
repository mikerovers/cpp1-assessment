#include "pch.h"
#include "CheatCommand.h"


CheatCommand::CheatCommand()
{
}


CheatCommand::~CheatCommand()
{
}

void CheatCommand::Execute(Game * const game)
{
	Player * const player = game->GetPlayer();
	player->CheatBaseStats();
}
