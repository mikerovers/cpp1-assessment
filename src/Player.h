#pragma once
#include "Stat.h"


class Player
{
public:
	Player();
	~Player();

	void SetStat(Stat* const newStat);
	void SetCurrentRoom(class BaseRoom* room);

	class BaseRoom* GetCurrentRoom();
private:
	Stat* stat;
	class BaseRoom* _currentRoom;

};

