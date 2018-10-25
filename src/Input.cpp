#include "pch.h"
#include "Input.h"
#include <iostream>
#include <sstream>


Input::Input()
{
}


Input::~Input()
{
}

int Input::GetIntInput() const
{
	char line[50];
	std::cin >> line;
	int number;
	std::istringstream iss(line);
	iss >> number;
	if (iss.eof() == false)
	{
		return 0;
	}
	return number;
}

char* Input::GetInput() const
{
	char line[50];
	std::cin >> line;
	return line;
}
