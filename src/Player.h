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
	void SetCurrentRoom(class BaseRoom* const room);

	class BaseRoom* const GetCurrentRoom();

	void MoveTo(MonsterHolder* monsterHolder, class BaseRoom* const room);
	int const GetHealth() const;
	int const SetHealth(const int amount);
	int const SetHealthConst(const int amount);

	Inventory* const GetInventory() const;
	Item* const PickUpitem();

	friend std::ostream& operator<<(std::ostream& os, const Player& pl);
	int const GetBaseAttack() const;
	int const GetBaseDefence() const;
	bool const GetDefence() const;

	void SetExperience(int const experience);
	void SetLevel(int const level);
	void SetSkillpoints(int const skillpoints);
	int const GetLevel() const;
	int const GetExperience() const;
	int const GetSkillpoints() const;


	void AddExperience(int const exp);
	int const IncreaseAttackStat();

	void CheatBaseStats();
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

