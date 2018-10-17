#pragma once
#include "ICommand.h"
class ShowMapCommand :
	public ICommand
{
public:
	ShowMapCommand();
	~ShowMapCommand();
	void Execute(Game* game);
};

