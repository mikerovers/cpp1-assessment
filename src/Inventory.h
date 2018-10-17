#pragma once
#include "Item.h"

class Inventory
{
public:
	explicit Inventory(int size);
	~Inventory();

	const int size;
	void PrintInventory();
	bool SetItem(Item* item);
	bool SetItemInSpot(Item* item, const int index);
	Item* GetItem(const int index);
private:
	Item* items[5];
};
