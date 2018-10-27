#pragma once
#include "Stat.h"
#include "MonsterHolder.h"
#include "Inventory.h"

class Player
{
public:
	Player();
	~Player();

	void SetStat(Stat* const newStat);
	void SetCurrentRoom(class BaseRoom* room);

	class BaseRoom* GetCurrentRoom();
	Item* PickUpitem(Inventory* inventory);

	void MoveTo(MonsterHolder* monsterHolder, class BaseRoom* room);
private:
	Stat* stat;
	class BaseRoom* _currentRoom;

};

