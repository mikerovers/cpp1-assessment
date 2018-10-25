#pragma once
class ContentTranslator
{
public:
	ContentTranslator();
	~ContentTranslator();

	char* GetDescription(int roomSize, int tidyness, int layout);
};

