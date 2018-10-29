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
	Item* item = game->GetPlayer()->PickUpitem();
	Output* output = game->GetOutput();
	output->ShowPickedUpItem(item);
}
