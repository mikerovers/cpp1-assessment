#pragma once
#include "Stat.h"
#include "MonsterHolder.h"

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
	int GetBaseAttack() const;
	int GetBaseDefence() const;
private:
	Stat* stat;
	class BaseRoom* _currentRoom;
	int health;
	int baseAttack;
	int baseDefence;
};

