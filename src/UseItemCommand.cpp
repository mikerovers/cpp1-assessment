#include "pch.h"
#include "UseItemCommand.h"
#include "Input.h"

void UseItemCommand::Execute(Game* game)
{
	auto* _input = new Input();
	auto* _output = new Output();

	_output->PrintInventory(game->GetInventory());
	_output->AskForItem();

	int input = -1;
	while (input == -1 || input > 5)
	{
		input = _input->GetIntInput();
	}

	if (input < 5)
	{
		auto* inventory = game->GetInventory();
		_output->PrintItemUsed(inventory->GetItem(input));
		inventory->GetItem(input)->Use();
	}

	delete _input;
	delete _output;
}
