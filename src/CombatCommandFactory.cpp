#include "pch.h"
#include "CombatCommandFactory.h"
#include "CharArrayComparator.h"
#include "ShowCommandsCommand.h"
#include "FlightCommand.h"
#include "CheckInventoryCommand.h"
#include "UseItemCommand.h"
#include "NullCommand.h"
#include "AttackCommand.h"
#include "StatCommand.h"

ICommand* CombatCommandFactory::RetrieveCommand(char command[]) const
{
	const auto const comparator = new (_NORMAL_BLOCK, __FILE__, __LINE__) CharArrayComparator();
	ICommand* returnCommand;
	if (comparator->Compare("commands", command, 8)) {
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) ShowCommandsCommand();
	}
	else if (comparator->Compare("attack", command, 6))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) AttackCommand();
	}
	else if (comparator->Compare("flight", command, 6)) {
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) FlightCommand();
	}
	else if (comparator->Compare("inventory", command, 9))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) CheckInventoryCommand();
	}
	else if (comparator->Compare("item", command, 4))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) UseItemCommand();
	}
	else if (comparator->Compare("stats", command, 5))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) StatCommand();
	}
	else {
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) NullCommand();
	}

	delete comparator;

	return returnCommand;
}
