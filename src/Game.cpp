#include "pch.h"

#include "Game.h"
#include "DungeonBuilder.h"
#include "Output.h"
#include "Input.h"
#include "CommandFactory.h"
#include "CombatController.h"
#include "Inventory.h"
#include "MonsterHolder.h"
#include "MonsterFileParser.h"
#include "MonsterParsingException.h"


void Game::Init()
{
	int monsterCount = 14;
	_output = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) Output();
	_input = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) Input();

	_output->ShowIntroduction();

	_monsterHolder = new (_NORMAL_BLOCK, __FILE__, __LINE__) MonsterHolder(monsterCount);

	try {
		auto *monsterParser = new (_NORMAL_BLOCK, __FILE__, __LINE__) MonsterFileParser;
		monsterParser->parse("monsters.txt", _monsterHolder);

		delete monsterParser;
	}
	catch (MonsterParsingException& e) {
		std::cerr << e.what() << "\n";
	}
}

Game::Game()
{

}

void Game::Setup() {
	int width = 0, height = 0, depth = 0;
	while (width <= 0) {
		_output->AskForDungeonWidth();
		width = _input->GetIntInput();
	}
	while (height <= 0) {
		_output->AskForDungeonHeight();
		height = _input->GetIntInput();
	}
	while (depth <= 0) {
		_output->AskForDungeonDepth();
		depth = _input->GetIntInput();
	}
	_currentLevel = depth - 1;
	
	_player = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) Player();
	_inventory = new (_NORMAL_BLOCK, __FILE__, __LINE__) Inventory(5);
	_combatController = new (_NORMAL_BLOCK, __FILE__, __LINE__) CombatController(_inventory, _player);
	// _combatController->Start(_monsterHolder->GetRandomMonsterByLevelRange(1, 10), this);
	DungeonBuilder* builder = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) DungeonBuilder();
	_dungeon = builder->BuildDungeon(_player, width, height, depth);
	delete builder;
}

void Game::Start() 
{
	_running = true;
	CommandFactory* commandFactory = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) CommandFactory();
	ICommand* command;

	_output->ClearScreen();
	_output->ShowGameStarted();
	while (Game::_running) {
		char line[50];
		std::cin >> line;
		_output->ClearScreen();
		command = commandFactory->RetrieveCommand(line);
		command->Execute(this);
		delete command;
	}

	delete _input;
	delete _output;
	delete _inventory;
	delete _dungeon;
	delete _monsterHolder;
	delete _combatController;
	delete commandFactory;
}

Dungeon * Game::GetDungeon() const
{
	return _dungeon;
}

Output * Game::GetOutput() const
{
	return _output;
}

Input * Game::GetInput() const
{
	return _input;
}

Inventory* Game::GetInventory() const
{
	return _inventory;
}

Player * Game::GetPlayer() const
{
	return _player;
}

MonsterHolder * Game::GetMonsterHolder() const
{
	return _monsterHolder;
}

int Game::GetCurrentLevel() const
{
	return _currentLevel;
}

void Game::SetCurrentLevel(int level)
{
	_currentLevel = level;
}

void Game::SetRunning(bool const running)
{
	_running = running;
}

Game::~Game()
{

}
