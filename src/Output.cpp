#include "pch.h"
#include "Output.h"
#include "Dungeon.h"
#include "NullItem.h"

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

void Output::PrintInventory(Inventory* const inventory) const
{
	printf("Inventory:\n");
	for (auto i = 0; i < inventory->size; i++) {
		if (typeid(inventory->GetItem(i)) != typeid(NullItem)) {
			if (i == 0 || i == inventory->size - 1) {
				std::cout << inventory->GetItem(i)->GetName();
			}
			else {
				std::cout << " - " << inventory->GetItem(i)->GetName() << " - ";
			}
		}
	}
	printf("\n");
}

void Output::PrintItemUsed(Item* const item) const
{
	printf("You used %s!\n", item->GetName());
}

void Output::PrintNothingHappened(const Item* item) const
{
	printf("Nothing happened with %s \n", item->GetName());
}

void Output::AskForItem() const
{
	printf("Which item do you want to use (0 - 4)? \n");
}

void Output::PrintHealthIncrease(const int amount) const
{
	printf("Your health has increased with %d points.\n", amount);
}

void Output::ShowCommands() const {
	printf("\"Commands\":		Toont de commando's\n");
	printf("\"Kaart\":		Toont de kaart van de kerker\n");
	printf("\"Inventory\":			Laat de inventory zien\n");
	printf("\"Item\":			Gebruik item uit inventory\n");
	printf("\"Exit\":			Sluit de applicatie\n");
}

void Output::ClearScreen() const {
	system("CLS");
}

void Output::ShowMap(Dungeon* const dungeon, int level) const {
	BaseRoom** grid = dungeon->GetGrid(level);
	int width = dungeon->GetWidth();
	int height = dungeon->GetHeight();

	printf("Kerker kaart: \n");
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			std::cout << grid[h][w].GetDisplayValue() << " ";

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


void Output::ShowNeighbours(Dungeon* const dungeon, int level) const {
	BaseRoom** grid = dungeon->GetGrid(level);
	int width = dungeon->GetWidth();
	int height = dungeon->GetHeight();

	int counter = 0;
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			BaseRoom* northRoom = grid[h][w].GetNorthNeighbour();
			BaseRoom* eastRoom = grid[h][w].GetEastNeighbour();
			BaseRoom* southRoom = grid[h][w].GetSouthNeighbour();
			BaseRoom* westRoom = grid[h][w].GetWestNeighbour();

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
