#pragma once
class BaseRoom
{
private:
	BaseRoom* _northNeighBour;
	BaseRoom* _eastNeighBour;
	BaseRoom* _southNeighBour;
	BaseRoom* _westNeighBour;

	bool _hasPlayer = false;
	bool _visited = false;
protected:
	char _displayValue;
public:
	BaseRoom();
	~BaseRoom();
	BaseRoom(const BaseRoom &obj);

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

