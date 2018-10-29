#include "pch.h"
#include "Shoes.h"
#include "Output.h"


Shoes::Shoes() : Item(const_cast<char*>("Shoes"))
{
}

Stat* Shoes::Handle(Stat* stat) const
{
	stat->defense += 15;
	stat->attack += 15;

	return AbstractStatHandler::Handle(stat);
}

void Shoes::Use()
{
	auto* output = new Output();
	output->PrintNothingHappened(this);
	delete output;
}

