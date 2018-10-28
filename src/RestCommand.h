#pragma once
#include "ICommand.h"

class RestCommand : public ICommand
{
public:
	RestCommand();
	~RestCommand();
	void Execute(Game* game) override;
};

