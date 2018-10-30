#pragma once
#include "Item.h"
#include "AbstractStatHandler.h"

class BroadSword : public Item
{
public:
	BroadSword();

	Stat* Handle(Stat* const stat) const override;
	void Use() override;
};
