#include "pch.h"
#include "CharArrayComparator.h"
#include "Output.h"
#include <cctype> 

CharArrayComparator::CharArrayComparator() {

}

CharArrayComparator::~CharArrayComparator() {

}

bool CharArrayComparator::Compare(char const array1[], char const array2[], int const size) const
{
	for (int i = 0; i < size; i++) {
		if (std::tolower(array1[i]) != std::tolower(array2[i])) {
			return false;
		}
	}
	return true;
}


