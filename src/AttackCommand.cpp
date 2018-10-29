#include "pch.h"
#include "AttackCommand.h"
#include "Inventory.h"
#include <ctime>
#include <random>
#include "Output.h"
#include "Stat.h"

AttackCommand::~AttackCommand()
{
}

void AttackCommand::Execute(Game* game)
{
}

void AttackCommand::Execute(Game* game, Monster* monster)
{
	auto* player = game->GetPlayer();
	auto* inventory = game->GetInventory();
	auto* stat = inventory->GetStat();

	// Player attack.
	const auto monsterHasEvaded = monster->getDefence();
	if (monsterHasEvaded)
	{
		game->GetOutput()->PrintAttackEvaded(monster);
	} else
	{
		auto playerDamage = stat->attack + player->GetBaseAttack();
		game->GetOutput()->PrintSuccessfullAttack(monster, playerDamage);
		monster->setHP(monster->getHP() - playerDamage);

	}

	if (monster->getHP() > 0) {
		// Monster attack.
		int damage = monster->getDamage();
		const auto playerEvaded = player->GetDefence();
		if (playerEvaded) {
			player->SetHealth(-damage);
			game->GetOutput()->PrintMonsterAttack(monster, damage);
		} else
		{
			game->GetOutput()->PrintPlayerEvaded(monster);
		}
	}
}
