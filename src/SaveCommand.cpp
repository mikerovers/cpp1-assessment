#include "pch.h"
#include "SaveCommand.h"
#include <fstream>
#include "FileNotOpenedException.h"
#include "Output.h"

SaveCommand::~SaveCommand() = default;

void SaveCommand::Execute(Game* game)
{
	auto* player = game->GetPlayer();

	try {
		std::ofstream outfile("player.txt", std::ofstream::binary);
		if (!outfile.is_open())
		{
			throw FileNotOpenedException();
		}

		outfile << *game->GetPlayer();

		outfile.close();
	} catch (FileNotOpenedException& e)
	{
		game->GetOutput()->PrintSavingError();
	}
	catch (...)
	{	
		printf("Unknown saving error :(");
	}
}
