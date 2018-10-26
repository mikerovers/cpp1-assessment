#include "pch.h"
#include "FlightCommand.h"
#include "Input.h"
#include "CharArrayComparator.h"

FlightCommand::FlightCommand()
{
}


FlightCommand::~FlightCommand()
{

}

void FlightCommand::Execute(Game* game)
{
	Output* output = game->GetOutput();
	Input* input = game->GetInput();
	Player* player = game->GetPlayer();
	MonsterHolder* monsterHolder = game->GetMonsterHolder();
	output->ShowExits(game->GetPlayer()->GetCurrentRoom());
	CharArrayComparator *comparator = new (_NORMAL_BLOCK, __FILE__, __LINE__) CharArrayComparator();
	bool valid = false;
	const char* command = nullptr;

	while (!command)
	{
		command = input->GetInput();
		char array[10];
		strcpy_s(array, 10, command);

		if (comparator->Compare("north", array, 5) && player->GetCurrentRoom()->GetNorthNeighbour()) {
			player->MoveTo(monsterHolder, player->GetCurrentRoom()->GetNorthNeighbour());
		}
		else if (comparator->Compare("east", array, 4) && player->GetCurrentRoom()->GetEastNeighbour()) {
			player->MoveTo(monsterHolder, player->GetCurrentRoom()->GetEastNeighbour());
		}
		else if (comparator->Compare("south", array, 5) && player->GetCurrentRoom()->GetSouthNeighbour()) {
			player->MoveTo(monsterHolder, player->GetCurrentRoom()->GetSouthNeighbour());
		}
		else if (comparator->Compare("west", array, 4) && player->GetCurrentRoom()->GetWestNeighbour()) {
			player->MoveTo(monsterHolder, player->GetCurrentRoom()->GetWestNeighbour());
		}
		else {
			command = nullptr;
		}
	}
	delete comparator;
}
