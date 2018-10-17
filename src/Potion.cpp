#include "pch.h"
#include "Potion.h"
#include <iostream>

void Potion::Use()
{
	std::cout << "You look at this weird looking potion called " << GetName() << "." << "\n";
}

Potion::Potion(char *name) : Item(name)
{

}
