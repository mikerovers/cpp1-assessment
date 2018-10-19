#include "pch.h"
#include "CheckInventoryCommand.h"


CheckInventoryCommand::CheckInventoryCommand()
{
}


CheckInventoryCommand::~CheckInventoryCommand()
{
}

void CheckInventoryCommand::Execute(Game* game)
{
	Inventory* inventory = game->GetInventory();
	Output* output = game->GetOutput();
	output->PrintInventory(inventory);
}
