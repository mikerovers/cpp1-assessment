#pragma once
#include "Player.h"
class BaseRoom
{
private:
	BaseRoom* _northNeighBour;
	BaseRoom* _eastNeighBour;
	BaseRoom* _southNeighBour;
	BaseRoom* _westNeighBour;

	char* _description;

	bool _hasPlayer = false;
	Player* _player = nullptr;
	bool _visited = false;

	void setRandomContent();
protected:
	char _displayValue;
public:
	BaseRoom();
	~BaseRoom();

	char GetDisplayValue();
	Player* GetPlayer();

	char* GetDescription();

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

