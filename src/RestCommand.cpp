#include "pch.h"
#include "RestCommand.h"
#include <ctime>
#include <random>
#include "CombatController.h"
#include "MonsterHolder.h"
#include "Output.h"

RestCommand::RestCommand()
{
}


RestCommand::~RestCommand()
{
}

void RestCommand::Execute(Game* game)
{
	auto* player = game->GetPlayer();
	if (player->GetHealth() >= 100)
	{
		game->GetOutput()->PrintRestNotAvailable();
	} else
	{
		std::default_random_engine generator;
		generator.seed(time(nullptr));
		const std::uniform_int_distribution<int> distribution(1, 6);
		const int result = distribution(generator);
		const bool attacked = result >= 1 && result <= 4;

		player->SetHealthConst(100);
		game->GetOutput()->PrintRest(player->GetHealth(), attacked);

		if (attacked)
		{
			game->GetCombatController()->Start(game->GetMonsterHolder()->GetRandomMonsterByLevelRange(1, 5), game);
		}
	}
}
