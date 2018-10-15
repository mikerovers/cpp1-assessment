#pragma once
#include "ICommand.h"
class ShowCommandsCommand :
	public ICommand
{
public:
	ShowCommandsCommand();
	~ShowCommandsCommand();
	void Execute(Game* game);
};

