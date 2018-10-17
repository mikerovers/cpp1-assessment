#include "pch.h"
#include "NullItem.h"

NullItem::NullItem() : Item(const_cast<char *>("*"))
{

}

NullItem::~NullItem()
{

}