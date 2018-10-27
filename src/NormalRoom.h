#pragma once
#include "BaseRoom.h"
class NormalRoom : public BaseRoom {
private:


public:
	NormalRoom();
	~NormalRoom();

	void PlayerEnters(MonsterHolder* monsterHolder);
	bool CanOverwriteRoom();


};