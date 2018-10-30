#include "pch.h"
#include "CheckInventoryCommand.h"
#include "Output.h"

CheckInventoryCommand::CheckInventoryCommand()
{
}


CheckInventoryCommand::~CheckInventoryCommand()
{
}

void CheckInventoryCommand::Execute(Game * const game)
{
	Inventory * const inventory = game->GetPlayer()->GetInventory();
	Output * const output = game->GetOutput();
	output->PrintInventory(inventory);
}
