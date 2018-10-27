#include "pch.h"
#include "Player.h"
#include "BaseRoom.h"

Player::Player(): stat(new Stat), health(100), baseAttack(20), baseDefence(20)
{
}


Player::~Player()
{
	delete stat;
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

int Player::GetBaseAttack() const
{
	return baseAttack;
}

int Player::GetBaseDefence() const
{
	return baseDefence;
}

void Player::SetStat(Stat* const newStat)
{
	delete stat;
	stat = newStat;
}
