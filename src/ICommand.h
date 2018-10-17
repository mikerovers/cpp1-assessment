#pragma once
#include "Game.h"
#include "Dungeon.h"
#include "Output.h"
class ICommand {
public:
	virtual void Execute(Game* game);
};