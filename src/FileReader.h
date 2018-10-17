#pragma once
#include <fstream>

class FileReader
{
public:
	std::ifstream openFile(const char path[]);
};
