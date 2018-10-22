#pragma once
#include "Stat.h"

class Player
{
public:
	Player();
	~Player();

	void SetStat(Stat* const newStat);
private:
	Stat* stat;
};

