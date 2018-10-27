#pragma once
#include "ICommand.h"

class NullCommand :
	public ICommand
{
public:
	NullCommand();
	~NullCommand();
	void Execute(Game* game);
};

