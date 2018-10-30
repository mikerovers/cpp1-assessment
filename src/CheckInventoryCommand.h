#pragma once
#include "ICommand.h"
class CheckInventoryCommand :
	public ICommand
{
public:
	CheckInventoryCommand();
	~CheckInventoryCommand();
	void Execute(Game *const game) override ;
};

