#pragma once
#include "BaseRoom.h"
class BaseStaircaseRoom :
	public BaseRoom
{
public:
	BaseStaircaseRoom();
	~BaseStaircaseRoom();
	virtual void PlayerEnters(MonsterHolder* monsterHolder);
	bool CanOverwriteRoom() override;
};

