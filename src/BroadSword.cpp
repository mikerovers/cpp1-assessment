#include "pch.h"
#include "BroadSword.h"

BroadSword::BroadSword(): Item(const_cast<char*>("Broadsword"))
{

}

Stat* BroadSword::Handle(Stat* stat) const
{
	stat->defense += 1;
	stat->attack += 15;
	stat->health += 0;

	return AbstractStatHandler::Handle(stat);
}

void BroadSword::Use()
{
}
