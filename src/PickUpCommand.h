#pragma once
#include "ICommand.h"
class PickUpCommand :
	public ICommand
{
public:
	PickUpCommand();
	~PickUpCommand();
	void Execute(Game* game);
};

