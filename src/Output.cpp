#include "pch.h"
#include "Output.h"
#include "Dungeon.h"
#include "NullItem.h"
#include "Game.h"

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

void Output::PrintInventory(const Inventory* inventory) const
{
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

void Output::AskDirections() const
{
}



void Output::ShowRoomDescription(BaseRoom * room) const
{
	printf(room->GetDescription());
}

void Output::ShowExits(BaseRoom * room) const
{
	printf("The following exists are available\n");

	if (room->GetNorthNeighbour()) {
		printf("north\n");
	}
	if (room->GetEastNeighbour()) {
		printf("east\n");
	}
	if (room->GetSouthNeighbour()) {
		printf("south\n");
	}
	if (room->GetWestNeighbour()) {
		printf("west\n");
	}
}

void Output::ShowEnemies(Monster * monster) const
{
	if (monster) {
		printf("Monster has spawned: %s\n", monster->getName());
	}
	else {
		printf("This room is clear of monsters\n");
	}
}


void Output::BlankLine() const
{
	printf("\n");
}

void Output::ShowOptions() const
{
	printf("What do you want to do?\n");
	printf("[fight|flight|search|rest|inventory|map]\n");
}

void Output::PrintPlayerDeath(const Monster* monster, const Inventory* inventory) const
{
	printf("You died by the claws of %s.", monster->getName());
	printf("You had the following items on you when you died: \n");
	PrintInventory(inventory);
}

void Output::PrintStartCombat(const Monster* monster) const
{
	printf("A wild %s appeared! Looks like it is level %u! \n", monster->getName(), monster->getLevel());
}

void Output::PrintVictory(const Player* player, const Monster* monster) const
{
	printf("You achieved victory over %s!\n", monster->getName());
	printf("Your remaining health is %d.\n", player->GetHealth());
}

void Output::PrintAttackEvaded(const Monster* monster) const
{
	printf("%s has evaded your attack. \n", monster->getName());
}

void Output::PrintSuccessfullAttack(const Monster* monster, const int damage) const
{
	printf("You decreased %s's with %d health points.\n", monster->getName(), damage);
}

void Output::PrintMonsterAttack(const Monster* monster, const int damage)
{
	printf("%s attacked you for %d of your health points.\n", monster->getName(), damage);
}

void Output::PrintPlayerEvaded(const Monster* monster) const
{
	printf("You evaded the attack from %s.", monster->getName());
}

void Output::PrintPlayerInfo(const Game* game) const
{
	printf("You have %d health left. \n", game->GetPlayer()->GetHealth());
	auto* stat = game->GetInventory()->GetStat();
	printf("Your current attack power is: %d\n", game->GetPlayer()->GetBaseAttack() + stat->attack);
	printf("Your current evasion rate is: %d\n", game->GetPlayer()->GetBaseDefence() + stat->defense);
	delete stat;
}

void Output::ShowCommands() const {
	printf("\"Commands\":		Show the commands\n");
	printf("\"Map\":			Show the map\n");
	printf("\"Inventory\":		Show the inventory\n");
	printf("\"Item\":			Use or destroy item from inventory\n");
	printf("\"Stats\":		Check your current stats \n");
	printf("\"Exit\":			Exit the game\n");
}

void Output::ClearScreen() const {
	system("CLS");
}

void Output::ShowMap(Dungeon* const dungeon, int level) const {
	BaseRoom** grid = dungeon->GetGrid(level);
	int width = dungeon->GetWidth();
	int height = dungeon->GetHeight();

	printf("Dungeon map: \n");
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			std::cout << grid[h][w].GetDisplayValue() << " ";

		}
		printf("\n");
	}

	printf("Legenda:\n");
	printf("P  : Player \n");
	printf("S  : Start location \n");
	printf("E  : End boss\n");
	printf("N  : Normal room\n");
	printf("L  : Stairs down\n");
	printf("H  : Stairs up \n");
	printf(".  : Not yet visited \n");
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
