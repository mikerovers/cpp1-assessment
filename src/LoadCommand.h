#pragma once
#include "ICommand.h"

class LoadCommand : public ICommand
{
public:
	~LoadCommand() override;
	void Execute(Game* game) override;
	Item* GetItem(char* description) const;
};
