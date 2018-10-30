#include "pch.h"
#include "Item.h"

Item::Item(char *name) : name(name)
{

}

char * Item::GetName() const
{
	return name;
}

Item::~Item()
{

}