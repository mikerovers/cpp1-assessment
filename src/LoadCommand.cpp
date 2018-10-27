﻿#include "pch.h"
#include "LoadCommand.h"
#include <fstream>
#include "FileNotOpenedException.h"
#include "Potion.h"
#include <string>
#include "CharArrayComparator.h"
#include "NullCommand.h"
#include "NullItem.h"
#include "BroadSword.h"

class CharArrayComparator;

LoadCommand::~LoadCommand()
{
}

void LoadCommand::Execute(Game* game)
{
	auto* player = new (_NORMAL_BLOCK, __FILE__, __LINE__) Player();

	std::ifstream infile("player.txt");
	if (!infile.is_open())
	{
		throw FileNotOpenedException();
	}

	int health;
	if (infile >> health)
	{
		player->SetHealthConst(health);
	}

	int maxLine = 50;
	char line[50];
	int count = 0;
	while (infile)
	{
		infile.getline(line, maxLine);
		if (strlen(line) != 0) {
			player->GetInventory()->SetItem(GetItem(line));
			count++;
			if (count == 5)
			{
				break;
			}
		}
	}

	infile.close();
	game->SetupPlayer(player);
}

Item* LoadCommand::GetItem(char* description) const
{
	const auto comparator = new (_NORMAL_BLOCK, __FILE__, __LINE__) CharArrayComparator();
	Item* item;
	if (comparator->Compare("potion", description, 6))
	{
		item = new (_NORMAL_BLOCK, __FILE__, __LINE__) Potion();
	} else if (comparator->Compare("broadsword", description, 10))
	{
		item = new (_NORMAL_BLOCK, __FILE__, __LINE__) BroadSword();
	} else
	{
		item = new (_NORMAL_BLOCK, __FILE__, __LINE__) NullItem();
	}

	delete comparator;
	return item;
}