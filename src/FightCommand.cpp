#include "pch.h"
#include "FightCommand.h"
#include "CombatController.h"
#include "BaseRoom.h"
#include "Output.h"


FightCommand::FightCommand()
{
}


FightCommand::~FightCommand()
{
}

void FightCommand::Execute(Game * game)
{
	Player* player = game->GetPlayer();
	Output* output = game->GetOutput();
	Monster* monster = player->GetCurrentRoom()->GetMonster();
	if (monster == nullptr || !monster) {
		output->NoMonsterToFight();
	}
	else {
		game->GetCombatController()->Start(monster, game);
	}
}
