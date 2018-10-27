#include "pch.h"
#include "Player.h"
#include "BaseRoom.h"

Player::Player(): stat(new Stat), health(100)
{
	_inventory = new (_NORMAL_BLOCK, __FILE__, __LINE__) Inventory(5);
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
	room->SetVisited();
	room->PlayerEnters(monsterHolder, temp);
}

int Player::GetHealth() const
{
	return health;
}

int Player::SetHealth(const int amount)
{
	return health += amount;
}

Inventory* Player::GetInventory() const
{
	return _inventory;
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
