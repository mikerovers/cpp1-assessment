#include "pch.h"
#include "PickUpCommand.h"
#include "Output.h"


PickUpCommand::PickUpCommand()
{
}


PickUpCommand::~PickUpCommand()
{
}

void PickUpCommand::Execute(Game * game)
{
	Item* const item = game->GetPlayer()->PickUpitem();
	Output* const output = game->GetOutput();
	output->ShowPickedUpItem(item);
}
