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

unsigned int RandomGenerator::Generate(int const first, int const second) { // TODO: returning a streamed value does not work like this
	std::default_random_engine generator;
	generator.seed(time(0));

	//voorbeeld 1
	std::uniform_int_distribution<int> distribution1(1, 10);
	int result = 0;
	result << distribution1(generator);
	return result;
}