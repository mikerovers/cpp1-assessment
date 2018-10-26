#pragma once
#include "ICommand.h"

class UseItemCommand : public ICommand
{
public:
	void Execute(Game* game) override;
};
