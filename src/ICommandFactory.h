#pragma once
#include "ICommand.h"

class ICommandFactory
{
public:
	virtual ~ICommandFactory() = default;
	virtual ICommand* RetrieveCommand(char command[]) const = 0;
};
