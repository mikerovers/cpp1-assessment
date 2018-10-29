#pragma once
#include "BaseStaircaseRoom.h"
class UpStaircaseRoom :
	public BaseStaircaseRoom
{
private:
	class DownStaircaseRoom* _downStairsRoom;
public:
	UpStaircaseRoom();
	~UpStaircaseRoom();
};

