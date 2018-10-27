#pragma once
#include "ICommandFactory.h"

class CombatCommandFactory : public ICommandFactory
{
public:
	ICommand* RetrieveCommand(char command[]) const override;
};
