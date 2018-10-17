#pragma once
#include <exception>

class FileNotOpenedException : public std::exception
{
public:
	explicit FileNotOpenedException();

	const char* what() const noexcept override
	{
		return "File could not be opened.";
	}
};
