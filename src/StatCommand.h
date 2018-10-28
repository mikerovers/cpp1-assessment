#pragma once
#include "ICommand.h"

class StatCommand : public ICommand
{
public:
	~StatCommand() override;
	void Execute(Game* game) override;
};
