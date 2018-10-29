#pragma once
#include "Stat.h"
#include "MonsterHolder.h"
#include <ostream>
#include "Inventory.h"

class Player
{
public:
	Player();
	Player(const int health);
	~Player();

	void SetStat(Stat* const newStat);
	void SetCurrentRoom(class BaseRoom* room);

	class BaseRoom* GetCurrentRoom();

	void MoveTo(MonsterHolder* monsterHolder, class BaseRoom* room);
	int GetHealth() const;
	int SetHealth(const int amount);
	int SetHealthConst(const int amount);

	Inventory* GetInventory() const;
	Item* PickUpitem();

	friend std::ostream& operator<<(std::ostream& os, const Player& pl);
	int GetBaseAttack() const;
	int GetBaseDefence() const;
	bool GetDefence() const;
private:
	Stat* stat;
	class BaseRoom* _currentRoom;
	int health;
	Inventory* _inventory;
	int baseAttack;
	int baseDefence;
};

