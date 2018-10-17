#pragma once
#include "ICommand.h"
class FlightCommand :
	public ICommand
{
public:
	FlightCommand();
	~FlightCommand();
	void Execute(Game * game);
};

