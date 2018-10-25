#include "pch.h"
#include "Player.h"
#include "BaseRoom.h"
#include "Output.h"


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

void Player::MoveTo(BaseRoom * room)
{
	_currentRoom->SetPlayer(nullptr);
	SetCurrentRoom(room);
	room->SetPlayer(this);
	room->SetVisited();
	Output* output = new Output();

	output->ShowRoomDescription(room);
}

void Player::SetStat(Stat* const newStat)
{
	delete stat;
	stat = newStat;
}
