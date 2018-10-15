#pragma once
class Room {
private:
	Room* _northNeighBour;
	Room* _eastNeighBour;
	Room* _southNeighBour;
	Room* _westNeighBour;
	int _displayValue;

public:
	Room();
	~Room();

	char GetDisplayValue();
	void SetDisplayValue(int value);

	Room* GetNorthNeighbour();
	void SetNorthNeighbour(Room* room);

	Room* GetEastNeighbour();
	void SetEastNeighbour(Room* room);

	Room* GetSouthNeighbour();
	void SetSouthNeighbour(Room* room);

	Room* GetWestNeighbour();
	void SetWestNeighbour(Room* room);


};