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

	Item* _item = nullptr;

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

	Monster* GetMonster() const;

	Item* GetItem() const;
	void RemoveItem();
	void SetItem();


	void SetUpStairsRoom(BaseRoom * const room);
	BaseRoom * GetUpStairsRoom() const;
	void SetDownStairsRoom(BaseRoom *const  room);
	BaseRoom * GetDownStairsRoom() const;

	void SetMonsterLevels(int const min, int const max);

	void SetRandomContent();
	char GetDisplayValue() const;
	char GetValue() const;
	Player* const GetPlayer() const;

	char* const GetDescription() const;

	void PlayerEnters(MonsterHolder* const monsterHolder, BaseRoom* const lastRoom);
	void PlayerLeaves();

	void SetVisited();
	void SetPlayer(Player* player);

	BaseRoom* const GetNorthNeighbour() const;
	void SetNorthNeighbour(BaseRoom* const room);

	BaseRoom* const GetEastNeighbour() const;
	void SetEastNeighbour(BaseRoom* const room);

	BaseRoom* const GetSouthNeighbour() const;
	void SetSouthNeighbour(BaseRoom* const room);

	BaseRoom* const GetWestNeighbour() const;
	void SetWestNeighbour(BaseRoom* const room);
};

