#include "pch.h"
#include "NullItem.h"
#include <iostream>
#include "Output.h"

NullItem::NullItem() : Item(const_cast<char *>("*"))
{

}

NullItem::~NullItem()
{
}

void NullItem::Use()
{
	auto* output = new Output();
	output->PrintNothinigHappened(this);
	delete output;
}
