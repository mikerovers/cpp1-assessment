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

	class Player* _player = nullptr;
	bool _visited = false;

	class Monster* _monster;
	Item* _item;

	void setMonster(class MonsterHolder* monsterHolder);
	void setItem();

	int _minMonsterLevel;
	int _maxMonsterLevel;
  
protected:
	char _displayValue;
public:
	BaseRoom();
	~BaseRoom();
	BaseRoom&operator=(const BaseRoom& other);

	Monster* GetMonster();

	Item* GetItem();




	void SetMonsterLevels(int min, int max);

	void SetRandomContent();
	char GetDisplayValue();
	Player* GetPlayer();

	char* GetDescription();

	void PlayerEnters(MonsterHolder* monsterHolder);
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

