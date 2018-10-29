#pragma once

#include "Item.h"
#include "MonsterHolder.h"
class BaseRoom
{
private:
	BaseRoom* _northNeighBour;
	BaseRoom* _eastNeighBour;
	BaseRoom* _southNeighBour;
	BaseRoom* _westNeighBour;


	char* _description = nullptr;


	bool _visited = false;

	Item* _item;

	void setItem();

	int _minMonsterLevel;
	int _maxMonsterLevel;
  
protected:
	char _displayValue;
	void setMonster(class MonsterHolder* monsterHolder);
	class Monster* _monster = nullptr;
	class Player* _player = nullptr;
	BaseRoom* _upStairsRoom = nullptr;
	BaseRoom* _downStairsRoom = nullptr;

public:
	BaseRoom();
	virtual ~BaseRoom();
	BaseRoom&operator=(const BaseRoom& other);

	Monster* GetMonster();

	Item* GetItem();


	void SetUpStairsRoom(BaseRoom * room);
	BaseRoom * GetUpStairsRoom();
	void SetDownStairsRoom(BaseRoom * room);
	BaseRoom * GetDownStairsRoom();

	void SetMonsterLevels(int min, int max);

	void SetRandomContent();
	char GetDisplayValue();
	Player* GetPlayer();

	char* GetDescription();

	virtual bool CanOverwriteRoom() = 0;
	void PlayerEnters(MonsterHolder* monsterHolder, BaseRoom* lastRoom);
	void PlayerLeaves();

	void SetVisited();
	void SetPlayer(Player* player);

	BaseRoom* GetNorthNeighbour();
	void SetNorthNeighbour(BaseRoom* room);

	BaseRoom* GetEastNeighbour();
	void SetEastNeighbour(BaseRoom* room);

	BaseRoom* GetSouthNeighbour();
	void SetSouthNeighbour(BaseRoom* room);

	BaseRoom* GetWestNeighbour();
	void SetWestNeighbour(BaseRoom* room);
};

