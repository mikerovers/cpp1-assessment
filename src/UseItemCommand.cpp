#include "pch.h"
#include "UseItemCommand.h"
#include "Input.h"
#include "Output.h"

void UseItemCommand::Execute(Game* game)
{
	auto* _input = new Input();
	auto* _output = new Output();

	_output->PrintInventory(game->GetPlayer()->GetInventory());
	_output->AskForItem();

	int input = -1;
	while (input == -1 || input > 5)
	{
		input = _input->GetIntInput();
	}

	if (input < 5)
	{
		auto* inventory = game->GetPlayer()->GetInventory();
		_output->PrintItemUsed(inventory->GetItem(input));
		inventory->UseItem(input);
	}

	delete _input;
	delete _output;
}
