#include "pch.h"
#include "RandomGenerator.h"
#include <random>
#include <ctime>
#include "Output.h"


RandomGenerator::RandomGenerator()
{
}


RandomGenerator::~RandomGenerator()
{
}

unsigned int RandomGenerator::Generate(int const first, int const second) const{ 
	std::random_device mch;
	std::default_random_engine generator(mch());

	std::uniform_int_distribution<int> distribution1(first, second);
	return distribution1(generator);;
}