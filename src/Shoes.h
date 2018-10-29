#pragma once
#include "Item.h"
class Shoes :
	public Item
{
public:
	Shoes();

	Stat* Handle(Stat* stat) const override;
	void Use() override;
};

