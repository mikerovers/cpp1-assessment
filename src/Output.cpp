#include "pch.h"
#include "Output.h"
#include "Dungeon.h"

Output::Output() {

}

Output::~Output() {

}

void Output::ShowIntroduction() const {
	printf("Welcome to Kerkers en Draken\n");
	printf("Door Mike Rovers en Wouter Bouwman\n");
	printf("----------------------------------------\n");
}

void Output::AskForDungeonWidth() const {
	printf("Hoe breed moet de dungeon worden? (1-20)\n");
}

void Output::AskForDungeonHeight() const {
	printf("Hoe hoog moet de dungeon worden? (1-20)\n");
}

void Output::AskForDungeonDepth() const {
	printf("Hoe diep moet de dungeon worden? (1-5)\n");
}

void Output::ShowGameStarted() const {
	printf("Het spel is gestart. Voer \"commands\" in voor beschikbare commando's.\n");
}

void Output::ShowCommands() const {
	printf("\"Commands\":		Toont de commando's\n");
	printf("\"Kaart\":		Toont de kaart van de kerker\n");
	printf("\"Exit\":			Sluit de applicatie\n");
}

void Output::ClearScreen() const {
	system("CLS");
}

void Output::ShowMap(Dungeon* const dungeon) const {
	Room** grid = dungeon->GetGrid();
	int width = dungeon->GetWidth();
	int height = dungeon->GetHeight();

	printf("Kerker kaart: \n");
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			printf("%i ", grid[h][w].GetDisplayValue());
		}
		printf("\n");
	}

	printf("Legenda:\n"); 
	printf("|- : Gangen \n");
	printf("S  : Start locatie \n");
	printf("E  : Eind vijand\n");
	printf("N  : Normale ruimte \n");
	printf("L  : Trap omlaag \n");
	printf("H  : Trap omhoog \n");
	printf(".  : Niet bezocht \n");
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

void Output::ShowFalseCommand() const {
	printf("Dit commando wordt niet herkent.");
	printf("\n");
}