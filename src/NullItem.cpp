#include "pch.h"
#include "NullItem.h"
#include <iostream>

NullItem::NullItem() : Item(const_cast<char *>("*"))
{

}

NullItem::~NullItem()
{
}

void NullItem::Use()
{

}
