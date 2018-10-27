#pragma once
#include <iostream>
#include "BaseRoom.h"
#include "Dungeon.h"
#include "Inventory.h"

class Output {
public:
	Output();
	~Output();
	void ShowIntroduction() const;
	void ShowMap(Dungeon* dungeon, int const currentLevel) const;
	void ShowNeighbours(Dungeon* dungeon, int const currentLevel) const;
	void ShowFalseCommand() const;
	void ClearScreen() const;
	void ShowCommands() const;
	void AskForDungeonWidth() const;
	void AskForDungeonHeight() const;
	void AskForDungeonDepth() const;
	void ShowGameStarted() const;
	void PrintInventory(Inventory* const inventory) const;
	void PrintItemUsed(Item* const item) const;
	void PrintNothingHappened(const Item* item) const;
	void AskForItem() const;
	void PrintHealthIncrease(const int amount) const;
	void AskDirections() const;
	void ShowRoomDescription(BaseRoom* room) const;
	void ShowExits(BaseRoom* room) const;
	void ShowEnemies(Monster* monster) const;
	void BlankLine() const;
	void ShowOptions() const;
	void ShowItem(Item* item) const;
	void ShowPickedUpItem(Item* item) const;
};
