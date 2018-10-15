#pragma once
class CharArrayComparator {
public:
	CharArrayComparator();
	~CharArrayComparator();
	bool Compare(char const array1[], char const array2[], int const size) const;
};