#pragma once
#include "BaseRoom.h"
class BaseStaircaseRoom :
	public BaseRoom
{
public:
	BaseStaircaseRoom();
	~BaseStaircaseRoom();
	void PlayerEnters(MonsterHolder* monsterHolder);
	bool CanOverwriteRoom();
};

