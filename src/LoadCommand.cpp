#include "pch.h"
#include "LoadCommand.h"
#include <fstream>
#include "FileNotOpenedException.h"
#include "Potion.h"
#include <string>
#include "CharArrayComparator.h"
#include "NullCommand.h"
#include "NullItem.h"
#include "BroadSword.h"
#include "Shield.h"
#include "Shoes.h"
#include "Helmet.h"

class CharArrayComparator;

LoadCommand::~LoadCommand()
{
}

void LoadCommand::Execute(Game* game)
{
	auto* const player = new (_NORMAL_BLOCK, __FILE__, __LINE__) Player();

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

	int level;
	if (infile >> level)
	{
		player->SetLevel(level);
	}

	int experience;
	if (infile >> experience)
	{
		player->SetExperience(experience);
	}

	int skillpoints;
	if (infile >> skillpoints)
	{
		player->SetSkillpoints(skillpoints);
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
	auto const comparator = new (_NORMAL_BLOCK, __FILE__, __LINE__) CharArrayComparator();
	Item * item;
	if (comparator->Compare("potion", description, 6))
	{
		item = new (_NORMAL_BLOCK, __FILE__, __LINE__) Potion() ;
	}
	else if (comparator->Compare("broadsword", description, 10))
	{
		item = new (_NORMAL_BLOCK, __FILE__, __LINE__) BroadSword();
	}
	else if (comparator->Compare("shield", description, 6))
	{
		item = new (_NORMAL_BLOCK, __FILE__, __LINE__) Shield();
	}
	else if (comparator->Compare("shoes", description, 5))
	{
		item = new (_NORMAL_BLOCK, __FILE__, __LINE__) Shoes();
	}
	else if (comparator->Compare("helmet", description, 6))
	{
		item = new (_NORMAL_BLOCK, __FILE__, __LINE__) Helmet();
	}
	else
	{
		item = new (_NORMAL_BLOCK, __FILE__, __LINE__) NullItem();
	}

	delete comparator;
	return item;
}
