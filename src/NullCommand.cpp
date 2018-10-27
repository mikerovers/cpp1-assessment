#include "pch.h"
#include "NullCommand.h"
#include "Output.h"

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
