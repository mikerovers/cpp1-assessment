#pragma once
#include "ICommand.h"
class IncreaseAttackStatCommand :
	public ICommand
{
public:
	IncreaseAttackStatCommand();
	~IncreaseAttackStatCommand();
	void Execute(Game* game);
};

