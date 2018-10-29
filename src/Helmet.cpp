#include "pch.h"
#include "Helmet.h"
#include "Output.h"

Helmet::Helmet() : Item(const_cast<char*>("Helmet"))
{
}

Stat* Helmet::Handle(Stat* stat) const
{
	stat->defense += 20;
	stat->attack += 2;

	return AbstractStatHandler::Handle(stat);
}

void Helmet::Use()
{
	auto* output = new Output();
	output->PrintNothingHappened(this);
	delete output;
}

