#include "pch.h"
#include "Inventory.h"
#include "NullItem.h"
#include <iostream>

Inventory::Inventory(int const size) : size(size)
{
	for (auto i = 0; i < size; i++) {
		items[i] = new NullItem();
	}
}

Inventory::~Inventory()
{
	for (auto i = 0; i < size; i++) {
		auto* item = items[i];
		delete item;
	}
}

bool Inventory::SetItem(Item *item)
{
	for (auto i = 0; i < size; i++) {
		auto a = items[i];

		if (typeid(*items[i]) == typeid(NullItem)) {
			delete items[i];
			items[i] = item;

			if (i > 0)
			{
				items[i - 1]->SetNext(items[i]);
			}

			return true;
		}
	}

	return false;
}

bool Inventory::UseItem(const int index)
{
	if (index < size)
	{
		items[index]->Use();
		delete items[index];
		items[index] = new NullItem();

		return true;
	}

	return false;
}

Item *Inventory::GetItem(const int index) const
{
	return items[index];
}

Stat* Inventory::GetStat() const
{
	return items[0]->Handle(new Stat);
}
