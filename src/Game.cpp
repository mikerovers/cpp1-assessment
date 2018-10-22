#include "pch.h"


#include "Game.h"
#include "DungeonBuilder.h"
#include "Output.h"
#include "Input.h"
#include "CommandFactory.h"
#include "State.h"
#include "Inventory.h"
#include "Potion.h"
#include "BroadSword.h"
#include "Shield.h"


void Game::Init()
{
	_output = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) Output();
	_input = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) Input();
	_inventory = new (_NORMAL_BLOCK, __FILE__, __LINE__) Inventory(5);

	_inventory->SetItem(new BroadSword());
	_inventory->SetItem(new Potion(const_cast<char*>("Weird looking potion")));
	_inventory->SetItem(new BroadSword());
	_inventory->SetItem(new Shield);

	_output->ShowIntroduction();
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

Inventory* Game::GetInventory() const
{
	return _inventory;
}

int Game::GetCurrentLevel() const
{
	return _currentLevel;
}

void Game::SetRunning(bool const running)
{
	_running = running;
}

Game::~Game()
{

}
