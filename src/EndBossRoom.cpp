#include "pch.h"
#include "EndBossRoom.h"


EndBossRoom::EndBossRoom()
{
	_displayValue = 'E';
}


EndBossRoom::~EndBossRoom()
{
}

bool EndBossRoom::CanOverwriteRoom()
{
	return false;
}
