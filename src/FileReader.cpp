#include "pch.h"
#include "FileReader.h"
#include "FileNotOpenedException.h"
#include "MonsterParsingException.h"

std::ifstream FileReader::openFile(const char *path)
{
	std::ifstream file;
	file.open(path);

	if (file.is_open()) {
		return file;
	}
	else {
		throw MonsterParsingException();
	}
}

