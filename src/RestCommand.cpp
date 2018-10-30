#include "pch.h"
#include "RestCommand.h"
#include <ctime>
#include <random>
#include "CombatController.h"
#include "MonsterHolder.h"
#include "Output.h"
#include "RandomGenerator.h"

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
		RandomGenerator* const random = new (_NORMAL_BLOCK, __FILE__, __LINE__) RandomGenerator();
		const int result = random->Generate(1, 6);
		delete random;

		const bool attacked = result >= 1 && result <= 4;

		player->SetHealthConst(100);
		game->GetOutput()->PrintRest(player->GetHealth(), attacked);

		if (attacked)
		{
			game->GetCombatController()->Start(game->GetMonsterHolder()->GetRandomMonsterByLevelRange(1, 5), game);
		}

	}
}
