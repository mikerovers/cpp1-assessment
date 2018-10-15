#pragma once
#include "ICommand.h"
class ExitCommand :
	public ICommand
{
public:
	ExitCommand();
	~ExitCommand();
	void Execute(Game* game);
};

