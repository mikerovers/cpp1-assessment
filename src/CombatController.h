#pragma once
#include "Monster.h"
#include "Game.h"
#include "CommandFactory.h"
#include "CombatCommandFactory.h"

class CombatController
{
public:
	CombatController(Inventory* inventory, Player* player);
	~CombatController();

	const bool Start(Monster* monster, Game *game) const;

private:
	Inventory* _inventory;
	Player* _player;
	CombatCommandFactory* _combatCommandFactory;
};
