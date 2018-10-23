#pragma once
#include "Item.h"

class Inventory
{
public:
	explicit Inventory(int const size);
	~Inventory();

	const int size;
	bool SetItem(Item* item);
	bool UseItem(const int index);
	Item* GetItem(const int index) const;
	Stat* GetStat() const;
private:
	Item* items[5]{};
};
