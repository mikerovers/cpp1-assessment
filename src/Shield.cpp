#include "pch.h"
#include "Shield.h"
#include "Output.h"

Shield::Shield(): Item(const_cast<char*>("Ugly shield"))
{
}

Stat* Shield::Handle(Stat* stat) const
{
	stat->defense += 50;
	stat->attack += 3;

	return AbstractStatHandler::Handle(stat);
}

void Shield::Use()
{
	auto* output = new Output();
	output->PrintNothingHappened(this);
	delete output;
}
