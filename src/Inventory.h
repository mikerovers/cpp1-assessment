#pragma once
#include "Item.h"
#include <ostream>

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

	friend std::ostream& operator<<(std::ostream& os, const Inventory& pl);
private:
	Item* items[5]{};
};
