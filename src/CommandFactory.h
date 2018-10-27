#pragma once
#include "ICommand.h"
#include "ICommandFactory.h"

class CommandFactory : public ICommandFactory
{
public:
	virtual ICommand* RetrieveCommand(char command[]) const;
};
