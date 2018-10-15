#include "pch.h"
#include "Output.h"
#include "Dungeon.h"

Output::Output() {

}

Output::~Output() {

}


void Output::ShowMap(Dungeon* const dungeon) const {
	Room** grid = dungeon->GetGrid();
	int width = dungeon->GetWidth();
	int height = dungeon->GetHeight();

	std::cout << "Welcome to Kerkers en Draken" << std::endl;
	std::cout << "***************************************************************" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	std::cout << "The instruction menu:" << std::endl << std::endl << std::endl;

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			printf("%i,", grid[h][w].GetDisplayValue());
		}
		printf("\n");
	}
}


void Output::ShowNeighbours(Dungeon* const dungeon) const {
	Room** grid = dungeon->GetGrid();
	int width = dungeon->GetWidth();
	int height = dungeon->GetHeight();

	int counter = 0;
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			Room* northRoom = grid[h][w].GetNorthNeighbour();
			Room* eastRoom = grid[h][w].GetEastNeighbour();
			Room* southRoom = grid[h][w].GetSouthNeighbour();
			Room* westRoom = grid[h][w].GetWestNeighbour();

			counter++;
			std::cout << "Nummer" << counter << ":" << std::endl;

			printf("North");
			if (northRoom != nullptr) printf("%i,", northRoom->GetDisplayValue());
			printf("\n");

			printf("East");
			if (eastRoom != nullptr) printf("%i,", eastRoom->GetDisplayValue());
			printf("\n");

			printf("South");
			if (southRoom != nullptr) printf("%i,", southRoom->GetDisplayValue());
			printf("\n");

			printf("West");
			if (westRoom != nullptr) printf("%i,", westRoom->GetDisplayValue());
			printf("\n");
		}
		printf("\n");
	}
}