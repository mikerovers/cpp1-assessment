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

	void SetExperience(int const experience);
	void SetLevel(int const level);
	void SetSkillpoints(int const skillpoints);
	int GetLevel() const;
	int GetExperience() const;
	int GetSkillpoints() const;

	void AddExperience(int const exp);
	int IncreaseAttackStat();
private:
	Stat* stat;
	int _level = 1;
	int _experience = 0;
	int _skillpoints = 0;
	class BaseRoom* _currentRoom;
	int health;
	Inventory* _inventory;
	int baseAttack;
	int baseDefence;
	void levelUp();

};

