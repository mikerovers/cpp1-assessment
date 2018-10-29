#include "pch.h"
#include "BroadSword.h"
#include "Output.h"

BroadSword::BroadSword(): Item(const_cast<char*>("Broadsword"))
{

}

Stat* BroadSword::Handle(Stat* stat) const
{
	stat->defense += 1;
	stat->attack += 15;

	return AbstractStatHandler::Handle(stat);
}

void BroadSword::Use()
{
	auto* output = new Output();
	output->PrintNothingHappened(this);
	delete output;
}

