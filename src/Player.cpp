#include "pch.h"
#include "Player.h"
#include "BaseRoom.h"

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

Item* Player::PickUpitem(Inventory* inventory)
{
	Item* item = _currentRoom->GetItem();
	if (item != nullptr) {
		inventory->SetItem(item);
	}
	return item;
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

void Player::SetStat(Stat* const newStat)
{
	delete stat;
	stat = newStat;
}
