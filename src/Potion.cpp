#include "pch.h"
#include "Potion.h"
#include <iostream>
#include "Output.h"

void Potion::Use()
{
	auto* const output = new (_NORMAL_BLOCK, __FILE__, __LINE__) Output();
	output->PrintHealthIncrease(15);
	delete output;
}

Potion::Potion(char *name) : Item(name)
{

}

Potion::Potion(): Item(const_cast<char*>("Potion"))
{
}
