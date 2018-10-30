#include "pch.h"
#include "FlightCommand.h"
#include "Input.h"
#include "CharArrayComparator.h"
#include "Output.h"

FlightCommand::FlightCommand()
{
}


FlightCommand::~FlightCommand()
{

}

void FlightCommand::Execute(Game* game)
{
	Output* const output = game->GetOutput();
	Input* const input = game->GetInput();
	Player* const player = game->GetPlayer();
	MonsterHolder* monsterHolder = game->GetMonsterHolder();
	output->ShowExits(game->GetPlayer()->GetCurrentRoom());
	CharArrayComparator * const comparator = new (_NORMAL_BLOCK, __FILE__, __LINE__) CharArrayComparator();
	bool valid = false;
	const char* command = nullptr;

	BaseRoom* roomToGo = nullptr;
	while (!command)
	{
		command = input->GetInput();
		char array[256];
		strcpy_s(array, 256, command);

		if (comparator->Compare("north", array, 5) && player->GetCurrentRoom()->GetNorthNeighbour()) {
			roomToGo = player->GetCurrentRoom()->GetNorthNeighbour();
		}
		else if (comparator->Compare("east", array, 4) && player->GetCurrentRoom()->GetEastNeighbour()) {
			roomToGo = player->GetCurrentRoom()->GetEastNeighbour();

		}
		else if (comparator->Compare("south", array, 5) && player->GetCurrentRoom()->GetSouthNeighbour()) {
			roomToGo = player->GetCurrentRoom()->GetSouthNeighbour();
		}
		else if (comparator->Compare("west", array, 4) && player->GetCurrentRoom()->GetWestNeighbour()) {
			roomToGo = player->GetCurrentRoom()->GetWestNeighbour();
		}
		else {
			command = nullptr;
		}
	}
	player->MoveTo(monsterHolder, roomToGo);
	if (roomToGo->GetUpStairsRoom()) {
		game->SetCurrentLevel(game->GetCurrentLevel() + 1);
	} else if (roomToGo->GetDownStairsRoom()) {
		game->SetCurrentLevel(game->GetCurrentLevel() - 1);
	}

	delete comparator;
}
