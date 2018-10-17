#include "pch.h"
#include "Inventory.h"
#include "NullItem.h"
#include <iostream>

Inventory::Inventory(int size) : size(size)
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

void Inventory::PrintInventory()
{
	std::cout << "Inventory:" << "\n";
	for (auto i = 0; i < size; i++) {
		if (typeid(items[i]) != typeid(NullItem)) {
			if (i == 0 || i == size - 1) {
				std::cout << items[i]->GetName();
			}
			else {
				std::cout << " - " << items[i]->GetName() << " - ";
			}
		}
	}
}

bool Inventory::SetItem(Item *item)
{
	for (auto i = 0; i < size; i++) {
		auto a = items[i];

		if (typeid(*items[i]) == typeid(NullItem)) {
			delete items[i];
			items[i] = item;

			return true;
		}
	}

	return false;
}

bool Inventory::SetItemInSpot(Item *item, const int index)
{
	if (items[index] == nullptr) {
		items[index] = item;

		return true;
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

Item *Inventory::GetItem(const int index)
{
	return items[index];
}
