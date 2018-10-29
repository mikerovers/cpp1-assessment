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
	Player* player = game->GetPlayer();
	Output* output = game->GetOutput();
	int skillpoints = player->GetSkillpoints();
	if (int attack = player->IncreaseAttackStat() != -1) {
		output->ShowAttackStatImproved(attack);
	}
	else {
		output->ShowNoSkillpoints();
	}
}
