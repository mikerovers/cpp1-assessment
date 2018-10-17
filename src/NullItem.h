#pragma once
#include "Item.h"

class NullItem : public Item
{
public:	   
	NullItem();
	~NullItem() override;
	void Use() override
	{};
};
