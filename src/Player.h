#pragma once
#include "Stat.h"
#include "MonsterHolder.h"
#include <ostream>
#include "Inventory.h"

class Player
{
public:
	Player();
	~Player();

	void SetStat(Stat* const newStat);
	void SetCurrentRoom(class BaseRoom* room);

	class BaseRoom* GetCurrentRoom();

	void MoveTo(MonsterHolder* monsterHolder, class BaseRoom* room);
	int GetHealth() const;
	int SetHealth(const int amount);
	Inventory* GetInventory() const;

	friend std::ostream& operator<<(std::ostream& os, const Player& pl);
private:
	Stat* stat;
	class BaseRoom* _currentRoom;
	int health;
	Inventory* _inventory;
};

