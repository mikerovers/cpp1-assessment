#include "pch.h"
#include "NormalRoom.h"
#include "Output.h"
#include "DownStaircaseRoom.h"

NormalRoom::NormalRoom() {
	_displayValue = 'N';
}

NormalRoom::~NormalRoom() {

}



void NormalRoom::PlayerEnters(MonsterHolder * monsterHolder)
{

}

bool NormalRoom::CanOverwriteRoom()
{
	return true;
}



