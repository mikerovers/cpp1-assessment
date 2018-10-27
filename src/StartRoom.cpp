#include "pch.h"
#include "StartRoom.h"


StartRoom::StartRoom()
{
	_displayValue = 'S';
}


StartRoom::~StartRoom()
{

}

bool StartRoom::CanOverwriteRoom()
{
	return false;
}
