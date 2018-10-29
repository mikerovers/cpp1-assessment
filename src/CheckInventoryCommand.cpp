#include "pch.h"
#include "CheckInventoryCommand.h"
#include "Output.h"

CheckInventoryCommand::CheckInventoryCommand()
{
}


CheckInventoryCommand::~CheckInventoryCommand()
{
}

void CheckInventoryCommand::Execute(Game* game)
{
	Inventory* inventory = game->GetPlayer()->GetInventory();
	Output* output = game->GetOutput();
	output->PrintInventory(inventory);
}
