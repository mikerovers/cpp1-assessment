#pragma once
#include "ICommand.h"
class FightCommand :
	public ICommand
{
public:
	FightCommand();
	~FightCommand();
	void Execute(Game* const game);

};

