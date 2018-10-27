#pragma once
#include "Item.h"

class Potion : public Item
{
public:
	explicit Potion(char* name);
	explicit Potion();
	void Use() override;
};
