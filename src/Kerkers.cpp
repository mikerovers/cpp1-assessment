#include "pch.h"
#pragma once

#define _CRTDBG_MAP_ALLOC  
#include "pch.h"
#include <iostream>
#include "DungeonBuilder.h"

#include <stdlib.h>
#include <crtdbg.h>
#include "Game.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game * const game = new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) Game();
	game->Init();
	game->Setup();
	game->Start();
	delete game;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) Item to create new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
