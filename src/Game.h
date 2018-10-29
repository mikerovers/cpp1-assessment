#pragma once
#include "Dungeon.h"
#include "MonsterHolder.h"
#include "Inventory.h"

class Game {
private:
	class Dungeon* _dungeon;
	class Player* _player;
	class Output* _output;
	class Input* _input;
	class MonsterHolder* _monsterHolder;
	class CombatController* _combatController;
	Inventory* _inventory;
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
	CombatController* GetCombatController() const;
	int GetCurrentLevel() const;
	void SetCurrentLevel(int level);
	void SetRunning(bool running);
	void SetupPlayer(Player* player = nullptr);
	Game();
	~Game();
};
