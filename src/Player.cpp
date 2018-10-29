#include "pch.h"
#include "Player.h"
#include "BaseRoom.h"
#include <random>
#include <ctime>
#include <fstream>

Player::Player(): stat(new Stat), health(80), baseAttack(20), baseDefence(20)
{
	_inventory = new (_NORMAL_BLOCK, __FILE__, __LINE__) Inventory(5);
}

Player::Player(const int health): health(health)
{
}


Player::~Player()
{
	delete stat;
	delete _inventory;
}

void Player::SetCurrentRoom(BaseRoom* room)
{
	_currentRoom = room;
}

BaseRoom * Player::GetCurrentRoom()
{
	return _currentRoom;
}

void Player::MoveTo(MonsterHolder* monsterHolder, BaseRoom * room)
{
	BaseRoom* temp = _currentRoom;
	_currentRoom->PlayerLeaves();

	SetCurrentRoom(room);

	room->SetPlayer(this);
	room->PlayerEnters(monsterHolder, temp);
	room->SetVisited();
}

int Player::GetHealth() const
{
	return health;
}

int Player::SetHealth(const int amount)
{
	return health += amount;
}

int Player::SetHealthConst(const int amount)
{
	return health = amount;
}

Inventory* Player::GetInventory() const
{
	return _inventory;
}


Item* Player::PickUpitem()
{
	Item* item = _currentRoom->GetItem();
	if (item != nullptr) {
		_inventory->SetItem(item);
	}
	return item;
}


int Player::GetBaseAttack() const
{
	return baseAttack;
}

int Player::GetBaseDefence() const
{
	if (baseDefence > 100)
	{
		return 100;
	}

	return baseDefence;
}

bool Player::GetDefence() const
{
	std::default_random_engine generator;
	generator.seed(time(nullptr));

	std::uniform_int_distribution<int> attackChangeDistribution(0, 100);
	int randomChange = attackChangeDistribution(generator);

	return randomChange > GetBaseDefence();
}

void Player::SetStat(Stat* const newStat)
{
	delete stat;
	stat = newStat;
}

std::ostream& operator<<(std::ostream& os, const Player& pl)
{
	os << pl.GetHealth() << "\r\n";
	os << *pl.GetInventory() << std::endl;

	return os;
}
