#pragma once
#include "Item.h"
class Helmet :
	public Item
{
public:
	Helmet();
	Stat* Handle(Stat* const stat) const override;
	void Use() override;
};

