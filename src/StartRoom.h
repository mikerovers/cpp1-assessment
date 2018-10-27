#pragma once
#include "BaseRoom.h"
class StartRoom :
	public BaseRoom
{
public:
	StartRoom();
	~StartRoom();
	void PlayerEnters(MonsterHolder* monsterHolder);
	bool CanOverwriteRoom();

};
