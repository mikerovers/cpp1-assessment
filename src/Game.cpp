#include "pch.h"


#include "Game.h"
#include "DungeonBuilder.h"
#include "Output.h"
#include "Input.h"
#include "CommandFactory.h"
#include "State.h"


void Game::Init()
{
	_output = new Output();
	_input = new Input();
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
	
	_player = new Player();

	DungeonBuilder* builder = new DungeonBuilder();
	_dungeon = builder->BuildDungeon(_player, width, height, depth);
}

void Game::Start() 
{
	_running = true;
	CommandFactory* commandFactory = new CommandFactory();
	ICommand* command;

	_output->ClearScreen();
	_output->ShowGameStarted();
	while (Game::_running) {
		char line[50];
		std::cin >> line;
		_output->ClearScreen();
		command = commandFactory->RetrieveCommand(line);
		command->Execute(this, _state);
	}
}

Dungeon * Game::GetDungeon() const
{
	return _dungeon;
}

Output * Game::GetOutput() const
{
	return _output;
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
	delete _dungeon;
	delete _output;
	delete _input;
}
