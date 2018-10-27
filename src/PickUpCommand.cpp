#include "pch.h"
#include "PickUpCommand.h"


PickUpCommand::PickUpCommand()
{
}


PickUpCommand::~PickUpCommand()
{
}

void PickUpCommand::Execute(Game * game)
{
	Item* item = game->GetPlayer()->PickUpitem(game->GetInventory());
	Output* output = game->GetOutput();
	output->ShowPickedUpItem(item);
}

