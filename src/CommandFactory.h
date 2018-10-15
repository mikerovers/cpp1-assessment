#pragma once
#include "ICommand.h"
class CommandFactory {

public:
	class ICommand* RetrieveCommand(char command[]);
};