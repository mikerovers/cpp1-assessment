#pragma once
#include "Item.h"
#include "CanAttackWith.h"
#include "AbstractStatHandler.h"

class BroadSword : public Item
{
public:
	BroadSword();

	Stat* Handle(Stat* stat) const override;
	void Use() override;
};
