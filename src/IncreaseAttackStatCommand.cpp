#include "pch.h"
#include "IncreaseAttackStatCommand.h"
#include "Output.h"


IncreaseAttackStatCommand::IncreaseAttackStatCommand()
{
}


IncreaseAttackStatCommand::~IncreaseAttackStatCommand()
{
}

void IncreaseAttackStatCommand::Execute(Game * game)
{
	Player* const player = game->GetPlayer();
	Output* const output = game->GetOutput();
	int skillpoints = player->GetSkillpoints();
	int attack = player->IncreaseAttackStat();
	if (attack != -1) {
		output->ShowAttackStatImproved(attack);
	}
	else {
		output->ShowNoSkillpoints();
	}
}
