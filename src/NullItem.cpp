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
	auto* const output = new (_NORMAL_BLOCK, __FILE__, __LINE__) Output();
	output->PrintNothingHappened(this);
	delete output;
}
