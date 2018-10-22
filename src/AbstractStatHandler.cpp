#include "pch.h"
#include "AbstractStatHandler.h"

AbstractStatHandler* AbstractStatHandler::SetNext(AbstractStatHandler* const handler)
{
	nextHandler = handler;

	return handler;
}

Stat* AbstractStatHandler::Handle(Stat* stat) const
{
	if (nextHandler != nullptr)
	{
		return this->nextHandler->Handle(stat);
	} else
	{
		return stat;
	}
}
