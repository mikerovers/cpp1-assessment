#include "pch.h"
#include "Player.h"
#include "BaseRoom.h"
#include <random>
#include <ctime>

Player::Player(): stat(new Stat), health(80), baseAttack(20), baseDefence(20)
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

int Player::SetHealthConst(const int amount)
{
	return health = amount;
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
