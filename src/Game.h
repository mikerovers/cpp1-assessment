#pragma once
#include "Dungeon.h"
#include "BaseRoom.h"
#include "MonsterHolder.h"

class Game {
private:
	class Dungeon* _dungeon;
	class Player* _player;
	class Output* _output;
	class Input* _input;
	class Inventory* _inventory;
	class MonsterHolder* _monsterHolder;
	int _state;
	bool _running;
	int _currentLevel;
public:
	void Init();
	void Setup();
	void Start();
	class Dungeon* GetDungeon() const;
	class Output* GetOutput() const;
	class Input* GetInput() const;
	class Inventory* GetInventory() const;
	class Player* GetPlayer() const;
	class MonsterHolder* GetMonsterHolder() const;
	int GetCurrentLevel() const;
	void SetRunning(bool running);
	Game();
	~Game();
};