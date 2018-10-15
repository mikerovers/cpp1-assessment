
#include "pch.h"
#include "CommandFactory.h"
#include "NullCommand.h"
#include "ShowMapCommand.h"
#include "ShowCommandsCommand.h"
#include "ExitCommand.h"
#include "CharArrayComparator.h"
#include "Output.h"

ICommand* CommandFactory::RetrieveCommand(char command[]) {
	CharArrayComparator *comparator = new CharArrayComparator();
	if (comparator->Compare("kaart", command, 5)) {
		return new ShowMapCommand();
	}
	else if (comparator->Compare("exit", command, 4)) {
		return new ExitCommand();
	}
	else if (comparator->Compare("commands", command, 4)) {
		return new ShowCommandsCommand();
	}
	else {
		return new NullCommand();
	}
}