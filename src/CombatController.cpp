#include "pch.h"
#include "CombatController.h"
#include "Output.h"
#include "CombatCommandFactory.h"
#include "AttackCommand.h"

class Player;

CombatController::CombatController(Inventory* inventory, Player* player): _inventory(inventory), _player(player)
{
	_combatCommandFactory = new (_NORMAL_BLOCK, __FILE__, __LINE__) CombatCommandFactory();
}

CombatController::~CombatController()
{
	delete _combatCommandFactory;
}

const bool CombatController::Start(Monster* monster, Game *game) const
{
	auto* output = new (_NORMAL_BLOCK, __FILE__, __LINE__) Output();
	auto inCombat = true;
	auto win = false;

	output->PrintStartCombat(monster);

	while(inCombat)
	{
		char line[50];
		std::cin >> line;
		output->ClearScreen();
		ICommand* command = _combatCommandFactory->RetrieveCommand(line);
		if (typeid(*command) == typeid(AttackCommand))
		{
			AttackCommand* aCommand = dynamic_cast<AttackCommand*>(command);
			aCommand->Execute(game, monster);
		}
		else {
			command->Execute(game);
		}

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
