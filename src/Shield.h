#pragma once
#include "Item.h"

class Shield : public Item
{
public:
	Shield();
	Stat* Handle(Stat* const stat) const override;
	void Use() override;
};
