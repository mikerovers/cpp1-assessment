#include "pch.h"
#include "Potion.h"
#include <iostream>
#include "Output.h"

void Potion::Use()
{
	auto* output = new Output();
	output->PrintHealthIncrease(15);
	delete output;
}

Potion::Potion(char *name) : Item(name)
{

}

Potion::Potion(): Item(const_cast<char*>("Potion"))
{
}
