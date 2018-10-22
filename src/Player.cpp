#include "pch.h"
#include "Player.h"


Player::Player(): stat(new Stat)
{
}


Player::~Player()
{
	delete stat;
}

void Player::SetStat(Stat* const newStat)
{
	delete stat;
	stat = newStat;
}
