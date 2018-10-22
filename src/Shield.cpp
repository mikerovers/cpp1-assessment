#include "pch.h"
#include "Shield.h"

Shield::Shield(): Item(const_cast<char*>("Ugly shield"))
{
}

Stat* Shield::Handle(Stat* stat) const
{
	stat->defense += 50;
	stat->attack += 3;
	stat->health += 10;

	return AbstractStatHandler::Handle(stat);
}

void Shield::Use()
{

}
