#pragma once
class RandomGenerator
{
public:
	RandomGenerator();
	~RandomGenerator();
	unsigned int Generate(int const first, int const second) const;
};

