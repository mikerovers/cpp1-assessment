#pragma once
class BaseRoom
{
private:
	BaseRoom* _northNeighBour;
	BaseRoom* _eastNeighBour;
	BaseRoom* _southNeighBour;
	BaseRoom* _westNeighBour;
	char _displayValue;
	bool _hasPlayer = false;

public:
	BaseRoom();
	~BaseRoom();

	char GetDisplayValue();
	bool HasPlayer();
	void SetHasPlayer(bool hasPlayer);

	BaseRoom* GetNorthNeighbour();
	void SetNorthNeighbour(BaseRoom* room);

	BaseRoom* GetEastNeighbour();
	void SetEastNeighbour(BaseRoom* room);

	BaseRoom* GetSouthNeighbour();
	void SetSouthNeighbour(BaseRoom* room);

	BaseRoom* GetWestNeighbour();
	void SetWestNeighbour(BaseRoom* room);
};

