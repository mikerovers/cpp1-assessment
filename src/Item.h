#pragma once

class Item
{
public:
	explicit Item(char *name);
	virtual ~Item();

	virtual void Use() = 0;
	virtual char* GetName() const;
protected:
	char* name;
};
