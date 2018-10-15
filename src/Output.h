#pragma once
#include <iostream>
#include "Room.h"
#include "Dungeon.h"

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
};