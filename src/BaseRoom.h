#pragma once
#include "Player.h"
class BaseRoom
{
private:
	BaseRoom* _northNeighBour;
	BaseRoom* _eastNeighBour;
	BaseRoom* _southNeighBour;
	BaseRoom* _westNeighBour;

	bool _hasPlayer = false;
	Player* _player = nullptr;
	bool _visited = false;
protected:
	char _displayValue;
public:
	BaseRoom();
	~BaseRoom();

	char GetDisplayValue();
	Player* GetPlayer();

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

