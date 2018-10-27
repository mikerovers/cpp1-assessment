#pragma once
#include "Game.h"

class ICommand {
public:
	virtual ~ICommand() = default;
	virtual void Execute(Game* game);
};