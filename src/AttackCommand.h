#pragma once
#include "ICommand.h"

class AttackCommand : public ICommand
{
public:
	~AttackCommand() override;
	void Execute(Game* game) override;
};
