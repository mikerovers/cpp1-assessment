#pragma once
#include "Dungeon.h"
#include "BaseRoom.h"

class Game {
private:
	class Dungeon* _dungeon;
	class Output* _output;
	class Input* _input;
	bool _running;
	int _currentLevel;
public:
	void Init();
	void Setup();
	void Start();
	class Dungeon* GetDungeon() const;
	class Output* GetOutput() const;
	int GetCurrentLevel() const;
	void SetRunning(bool running);
	Game();
	~Game();
};