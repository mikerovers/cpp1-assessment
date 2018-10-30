#include "pch.h"
#include "Player.h"
#include "BaseRoom.h"
#include <random>
#include <ctime>
#include <fstream>
#include "Output.h"

Player::Player(): stat(new (_NORMAL_BLOCK, __FILE__, __LINE__) Stat), health(80), baseAttack(20), baseDefence(20)
{
	_inventory = new (_NORMAL_BLOCK, __FILE__, __LINE__) Inventory(5);
}

Player::Player(int const health): health(health)
{
}


Player::~Player()
{
	delete stat;
	delete _inventory;
}

void Player::SetCurrentRoom(BaseRoom* const room)
{
	_currentRoom = room;
}

BaseRoom * const Player::GetCurrentRoom()
{
	return _currentRoom;
}

void Player::MoveTo(MonsterHolder* const monsterHolder, BaseRoom * const room)
{
	BaseRoom* const temp = _currentRoom;
	_currentRoom->PlayerLeaves();

	SetCurrentRoom(room);

	room->SetPlayer(this);
	room->PlayerEnters(monsterHolder, temp);
	room->SetVisited();
}

int const Player::GetHealth() const
{
	return health;
}

int const Player::SetHealth(const int amount)
{
	return health += amount;
}

int const Player::SetHealthConst(const int amount)
{
	return health = amount;
}

Inventory* const Player::GetInventory() const
{
	return _inventory;
}


Item* const Player::PickUpitem()
{
	Item* const item = _currentRoom->GetItem();
	_currentRoom->RemoveItem();
	if (item != nullptr) {
		_inventory->SetItem(item);
	}
	return item;
}


int const Player::GetBaseAttack() const
{
	return baseAttack;
}

int const Player::GetBaseDefence() const
{
	if (baseDefence > 100)
	{
		return 100;
	}

	return baseDefence;
}

bool const Player::GetDefence() const
{
	std::default_random_engine generator;
	generator.seed(time(nullptr));

	std::uniform_int_distribution<int> attackChangeDistribution(0, 100);
	int randomChange = attackChangeDistribution(generator);

	return randomChange > GetBaseDefence();
}

int const Player::GetLevel() const
{
	return _level;
}

int const Player::GetExperience() const
{
	return _experience;
}

int const Player::GetSkillpoints() const
{
	return _skillpoints;
}



void Player::AddExperience(int const exp)
{
	Output* const output = new (_NORMAL_BLOCK, __FILE__, __LINE__) Output();
	output->ShowExperienceGain(exp);
	_experience += exp;
	while (_experience >= 15 && _level != 10) {
		levelUp();
		output->LevelUp(_level, _skillpoints);
		_experience -= 15;
	}
	if (_experience > 15) {
		_experience = 15;
	}
	delete output;
}

int const Player::IncreaseAttackStat()
{
	if (_skillpoints == 0) {
		return -1;
	}

	_skillpoints--;
	
	baseAttack += 10;
	return baseAttack;
}

void Player::CheatBaseStats() 
{
	baseAttack += 1000;
	baseDefence += 1000;
}

void Player::levelUp() {
	_level++;
	_skillpoints++;
}

void Player::SetExperience(int const experience)
{
	_experience = experience;
}

void Player::SetLevel(int const level) {
	_level = level;
}

void Player::SetSkillpoints(int const skillpoints) 
{
	_skillpoints = skillpoints;
}

void Player::SetStat(Stat* const newStat)
{
	delete stat;
	stat = newStat;
}

std::ostream& operator<<(std::ostream& os, const Player& pl)
{
	os << pl.GetHealth() << "\r\n";
	os << pl.GetLevel() << "\r\n";
	os << pl.GetExperience() << "\r\n";
	os << pl.GetSkillpoints() << "\r\n";
	os << *pl.GetInventory() << std::endl;

	return os;
}
