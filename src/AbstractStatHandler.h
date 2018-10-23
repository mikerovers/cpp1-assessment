#pragma once
#include "Stat.h"

class AbstractStatHandler
{
public:
	AbstractStatHandler* SetNext(AbstractStatHandler* const handler);

	virtual Stat* Handle(Stat* stat) const;

private:
	AbstractStatHandler* nextHandler = nullptr;
};
