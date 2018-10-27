#pragma once
#include "BaseRoom.h"
class EndBossRoom :
	public BaseRoom
{
public:
	EndBossRoom();
	~EndBossRoom();
	void PlayerEnters(MonsterHolder* monsterHolder);
	bool CanOverwriteRoom();

};

