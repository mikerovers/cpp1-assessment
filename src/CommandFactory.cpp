
#include "pch.h"
#include "CommandFactory.h"
#include "NullCommand.h"
#include "ShowMapCommand.h"
#include "ShowCommandsCommand.h"
#include "ExitCommand.h"
#include "CharArrayComparator.h"
#include "Output.h"
#include "CheckInventoryCommand.h"
#include "FlightCommand.h"
#include "UseItemCommand.h"
#include "SaveCommand.h"

ICommand* CommandFactory::RetrieveCommand(char command[]) const {
	const auto comparator = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) CharArrayComparator();
	ICommand* returnCommand;
	if (comparator->Compare("map", command, 3)) {
		returnCommand = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) ShowMapCommand();
	}
	else if (comparator->Compare("exit", command, 4)) {
		returnCommand = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) ExitCommand();
	}
	else if (comparator->Compare("commands", command, 8)) {
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) ShowCommandsCommand();
	}
	else if (comparator->Compare("inventory", command, 9))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) CheckInventoryCommand();
	}
	else if (comparator->Compare("save", command, 4))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) SaveCommand();
	}
	else {
		returnCommand = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) NullCommand();
	}

	delete comparator;

	return returnCommand;
}
