#include "pch.h"
#include "Shield.h"
#include "Output.h"

Shield::Shield(): Item(const_cast<char*>("Ugly shield"))
{
}

Stat* Shield::Handle(Stat* const stat) const
{
	stat->defense += 50;
	stat->attack += 3;

	return AbstractStatHandler::Handle(stat);
}

void Shield::Use()
{
	auto* const output = new (_NORMAL_BLOCK, __FILE__, __LINE__) Output();
	output->PrintNothingHappened(this);
	delete output;
}
