#include "pch.h"
#include "FlightCommand.h"


FlightCommand::FlightCommand()
{
}


FlightCommand::~FlightCommand()
{

}

void FlightCommand::Execute(Game* game)
{
	Output* output = game->GetOutput();
	output->ShowDirections(game->GetPlayer());
}
