#pragma once
#include "Item.h"

class Potion : public Item
{
public:
	explicit Potion(char* const name);
	explicit Potion();
	void Use() override;
};
