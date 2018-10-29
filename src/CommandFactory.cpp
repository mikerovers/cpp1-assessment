
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
#include "FightCommand.h"
#include "CheatCommand.h"
#include "UseItemCommand.h"
#include "SaveCommand.h"
#include "CheckStatsCommand.h"
#include "StatCommand.h"
#include "RestCommand.h"
#include "PickUpCommand.h"
#include "IncreaseAttackStatCommand.h"

ICommand* CommandFactory::RetrieveCommand(char command[]) const {
	const auto comparator = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) CharArrayComparator();
	ICommand* returnCommand;
	if (comparator->Compare("map", command, 3)) {
		returnCommand = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) ShowMapCommand();
	}
	else if (comparator->Compare("exit", command, 4)) {
		returnCommand = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) ExitCommand();
	}
	else if (comparator->Compare("pickup", command, 6)) {
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) PickUpCommand();
	}
	else if (comparator->Compare("commands", command, 8)) {
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) ShowCommandsCommand();
	}
	else if (comparator->Compare("flight", command, 6))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) FlightCommand();
	}
	else if (comparator->Compare("fight", command, 5))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) FightCommand();
	}
	else if (comparator->Compare("inventory", command, 9))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) CheckInventoryCommand();
	}
	else if (comparator->Compare("item", command, 4))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) UseItemCommand();
	}
	else if (comparator->Compare("save", command, 4))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) SaveCommand();
	}
	else if (comparator->Compare("stats", command, 5))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) StatCommand();
	}
	else if (comparator->Compare("increase", command, 7))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) IncreaseAttackStatCommand();
	}
	else if (comparator->Compare("rest", command, 4))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) RestCommand();
	}
	else if (comparator->Compare("cheat", command, 5))
	{
		returnCommand = new (_NORMAL_BLOCK, __FILE__, __LINE__) CheatCommand();
	}
	else {
		returnCommand = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) NullCommand();
	}

	delete comparator;

	return returnCommand;
}
