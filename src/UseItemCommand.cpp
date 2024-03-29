﻿#include "pch.h"
#include "UseItemCommand.h"
#include "Input.h"
#include "Output.h"

void UseItemCommand::Execute(Game* game)
{
	auto* const _input = new (_NORMAL_BLOCK, __FILE__, __LINE__) Input();
	auto* const _output = new (_NORMAL_BLOCK, __FILE__, __LINE__) Output();

	_output->PrintInventory(game->GetPlayer()->GetInventory());
	_output->AskForItem();

	int input = -1;
	while (input == -1 || input > 5)
	{	
		input = _input->GetIntInput();
	}

	if (input < 5)
	{
		auto* const inventory = game->GetPlayer()->GetInventory();
		_output->PrintItemUsed(inventory->GetItem(input));
		inventory->UseItem(input);
	}

	delete _input;
	delete _output;
}
