#include "pch.h"
#include "SaveCommand.h"
#include <fstream>

SaveCommand::~SaveCommand() = default;

void SaveCommand::Execute(Game* game)
{
	auto* player = game->GetPlayer();

	try {
		std::ofstream outfile("player.txt", std::ofstream::binary);
		outfile << *game->GetPlayer();

		outfile.close();
	} catch (std::exception& e)
	{	
		printf("Saving error.");
	}
}
