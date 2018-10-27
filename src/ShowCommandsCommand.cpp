#include "pch.h"
#include "ShowCommandsCommand.h"
#include "Output.h"

ShowCommandsCommand::ShowCommandsCommand()
{
}


ShowCommandsCommand::~ShowCommandsCommand()
{
}

void ShowCommandsCommand::Execute(Game * game)
{
	Output* output = game->GetOutput();
	output->ShowCommands();
}
