#pragma once
#include "ICommand.h"

class SaveCommand : public ICommand
{
public:
	~SaveCommand() override;
	void Execute(Game* game) override;
};
