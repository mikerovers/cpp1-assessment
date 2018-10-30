#include "pch.h"
#include "StatCommand.h"
#include "Output.h"

StatCommand::~StatCommand()
= default;

void StatCommand::Execute(Game* game)
{
	auto* const output = game->GetOutput();
	output->PrintPlayerInfo(game);
}
