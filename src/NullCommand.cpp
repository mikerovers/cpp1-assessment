#include "pch.h"
#include "NullCommand.h"


NullCommand::NullCommand()
{
}


NullCommand::~NullCommand()
{
}

void NullCommand::Execute(Game* game)
{
	Output* output = game->GetOutput();
	output->ShowFalseCommand();
}
