#include "pch.h"
#include "CheatCommand.h"


CheatCommand::CheatCommand()
{
}


CheatCommand::~CheatCommand()
{
}

void CheatCommand::Execute(Game * game)
{
	Player* player = game->GetPlayer();
	player->CheatBaseStats();
}
