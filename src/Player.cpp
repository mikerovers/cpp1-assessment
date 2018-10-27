#include "pch.h"
#include "Player.h"
#include "BaseRoom.h"

Player::Player(): stat(new Stat), health(100)
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
	_currentRoom->PlayerLeaves();
	SetCurrentRoom(room);

	room->SetPlayer(this);
	room->SetVisited();
	room->PlayerEnters(monsterHolder);
}

int Player::GetHealth() const
{
	return health;
}

int Player::SetHealth(const int amount)
{
	return health += amount;
}

void Player::SetStat(Stat* const newStat)
{
	delete stat;
	stat = newStat;
}
