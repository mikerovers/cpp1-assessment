#include "pch.h"
#include "Player.h"


Player::Player(): stat(new Stat)
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

void Player::SetStat(Stat* const newStat)
{
	delete stat;
	stat = newStat;
}
