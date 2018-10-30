#pragma once
#include "Item.h"
#include <ostream>

class Inventory
{
public:
	explicit Inventory(int const size);
	~Inventory();

	const int size;
	bool const SetItem(Item* const item);
	bool const UseItem(int const index);
	Item* const GetItem(int const index) const;
	Stat* const GetStat() const;

	friend std::ostream& operator<<(std::ostream& os, const Inventory& pl);
private:
	Item*  items[5]{};
};
