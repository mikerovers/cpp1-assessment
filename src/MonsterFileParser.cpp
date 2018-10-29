#include "pch.h"
#include "MonsterHolder.h"
#include "MonsterFileParser.h"
#include "MonsterParsingException.h"
#include "FileReader.h"
#include "FileNotOpenedException.h"

const int MAXLINE = 256;

void MonsterFileParser::parse(const char path[], MonsterHolder* monsterHolder)
{
	auto *reader = new FileReader();

	try {
		auto monsterFile = reader->openFile(path);
		delete reader;

		char oneLine[MAXLINE];
		int counter = 0;
		while (monsterFile) {
			monsterFile.getline(oneLine, MAXLINE);

			Monster *monster = parseMonster(oneLine);
			if (monster != nullptr) {
				monsterHolder->AddMonster(monster, counter);
				counter++;
			}

			if (counter >= 14) {
				break;
			}
		}

		monsterFile.close();
	}
	catch (FileNotOpenedException e) {

	}
	catch (MonsterParsingException e) {

	} 
}


Monster* MonsterFileParser::parseMonster(const char m[])
{
	std::cmatch matches;

	if (std::regex_search(m, matches, mRegex)) {
		try {
			auto m = matches[1].str();
			const char * p = _strdup(m.c_str());

			auto* monster = new (_NORMAL_BLOCK, __FILE__, __LINE__) Monster(
				p,
				static_cast<unsigned int>(atoi(matches[2].str().c_str())),
				static_cast<unsigned int>(atoi(matches[3].str().c_str())),
				static_cast<unsigned int>(atoi(matches[4].str().c_str())),
				static_cast<unsigned int>(atoi(matches[5].str().c_str())),
				static_cast<unsigned int>(atoi(matches[6].str().c_str())),
				static_cast<unsigned int>(atoi(matches[7].str().c_str())),
				static_cast<unsigned int>(atoi(matches[8].str().c_str()))
			);

			return monster;
		}
		catch (int e) {
			throw MonsterParsingException();
		}
	}
	else {
		return nullptr;
	}
}

MonsterFileParser::MonsterFileParser()
{
	mRegex = (R"(\[([a-z ]+);([\d]+|BAAS);(\d+)x(\d);(\d+)-(\d+);(\d+);(\d+)\])");
}