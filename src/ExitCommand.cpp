#include "pch.h"
#include "ExitCommand.h"


ExitCommand::ExitCommand()
{
}


ExitCommand::~ExitCommand()
{
}

void ExitCommand::Execute(Game* game)
{
	game->SetRunning(false);
}
