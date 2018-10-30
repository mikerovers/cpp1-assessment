#pragma once
#include "ICommand.h"
class CheatCommand :
	public ICommand
{
public:
	CheatCommand();
	~CheatCommand();
	void Execute(Game * const game) ;
};

