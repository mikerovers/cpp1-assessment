#include "pch.h"
#include "CombatController.h"
#include "Output.h"
#include "CombatCommandFactory.h"

class Player;

CombatController::CombatController(Inventory* inventory, Player* player): _inventory(inventory), _player(player)
{
	_combatCommandFactory = new (_NORMAL_BLOCK, __FILE__, __LINE__) CombatCommandFactory();
}

CombatController::~CombatController()
{
	delete _combatCommandFactory;
}

const bool CombatController::Start(const Monster* monster, Game *game) const
{
	auto* output = new (_NORMAL_BLOCK, __FILE__, __LINE__) Output();
	auto inCombat = true;
	auto win = false;
	ICommand* command;

	output->PrintStartCombat(monster);

	while(inCombat)
	{
		char line[50];
		std::cin >> line;
		output->ClearScreen();
		command = _combatCommandFactory->RetrieveCommand(line);
		command->Execute(game);

		if (_player->GetHealth() <= 0)
		{
			output->PrintPlayerDeath(monster, _inventory);
			inCombat = false;
		}

		if (monster->getHP() <= 0)
		{
			output->PrintVictory(_player, monster);
			inCombat = false;
			win = true;
		}

		delete command;
	}

	delete output;

	return win;
}
