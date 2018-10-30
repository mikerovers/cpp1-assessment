#include "pch.h"
#include "ContentTranslator.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS


ContentTranslator::ContentTranslator()
{
}


ContentTranslator::~ContentTranslator()
{
}

char * ContentTranslator::GetDescription(int roomSize, int tidyness, int layout)
{
	char roomSizeArray[15];
	char tidynessArray[20];
	char layoutArray[50];
	char first[11] = "Het is een";
	char second[13] = " ruimte, met";

	switch (roomSize) {
		case 0: {
			strcpy_s(roomSizeArray, " kleine");
		}break;
		case 1: {
			strcpy_s(roomSizeArray, " gemiddelde");
		}break;
		case 2: {
			strcpy_s(roomSizeArray, " grote");
		}break;
	}



	switch (tidyness) {
		case 0: {
			strcpy_s(tidynessArray, " opgeruimde");
		}break;
		case 1: {
			strcpy_s(tidynessArray, " rommelige");
		}break;
	}

	switch (layout) {
		case 0: {
			strcpy_s(layoutArray, " vier stoelen in het midden van de kamer");
		}break;
		case 1: {
			strcpy_s(layoutArray, " een bed in de hoek");
		}break;
		case 2: {
			strcpy_s(layoutArray, " niks erin");
		}break;
	}

	size_t const firstLen = std::strlen(first);
	size_t const roomSizeLen = std::strlen(roomSizeArray);
	size_t const tidynessLen = std::strlen(tidynessArray);
	size_t const secondLen = std::strlen(second);
	size_t const layoutLen = std::strlen(layoutArray);

	char* const description = new char[firstLen + roomSizeLen + tidynessLen + secondLen + layoutLen + 1];
	int descrCounter = 0;

	for (int i = 0; i < firstLen; i++) {
		
		description[descrCounter] = first[i];
		descrCounter++;
	}

	for (int i = 0; i < roomSizeLen; i++) {
		description[descrCounter] = roomSizeArray[i];
		descrCounter++;
	}

	for (int i = 0; i < tidynessLen; i++) {
		description[descrCounter] = tidynessArray[i];
		descrCounter++;
	}

	for (int i = 0; i < secondLen; i++) {
		description[descrCounter] = second[i];
		descrCounter++;
	}

	for (int i = 0; i < layoutLen; i++) {
		description[descrCounter] = layoutArray[i];
		descrCounter++;
	}

	description[descrCounter] = '\0';

	return description;
}
