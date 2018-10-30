#include "pch.h"
#include "Monster.h"
#include <cstring>
#include <random>
#include <ctime>

unsigned int const Monster::getAttackChance() const
{
	return attackChance;
}

void Monster::setAttackChance(unsigned int const attackChance)
{
	Monster::attackChance = attackChance;
}

unsigned int const Monster::getAttacksPerRound() const
{
	return attacksPerRound;
}

void Monster::setAttacksPerRound(unsigned int const attacksPerRound)
{
	Monster::attacksPerRound = attacksPerRound;
}

unsigned int const Monster::getMinAmountOfDamage() const
{
	return minAmountOfDamage;
}

void Monster::setMinAmountOfDamage(unsigned int const minAmountOfDamage)
{
	Monster::minAmountOfDamage = minAmountOfDamage;
}

unsigned int const Monster::getMaxAmountOfDamage() const
{
	return maxAmountOfDamage;
}

void Monster::setMaxAmountOfDamage(unsigned int const maxAmountOfDamage)
{
	Monster::maxAmountOfDamage = maxAmountOfDamage;
}

unsigned int const Monster::getEvasionChance() const
{
	return evasionChance;
}

void Monster::setEvasionChance(unsigned int const evasionChance)
{
	Monster::evasionChance = evasionChance;
}

unsigned int const Monster::getLevel() const
{
	return level;
}

void Monster::setLevel(unsigned int const level)
{
	Monster::level = level;
}

const char* const Monster::getName() const
{
	return name;
}

void Monster::setName(const char * const nam)
{
	name = nam;
}

int const Monster::getHP() const
{
	return HP;
}

void Monster::setHP(const int HP)
{
	Monster::HP = HP;
}

Monster::Monster(const char *name, unsigned int const level, unsigned int const attackChance, unsigned int const attacksPerRound,
	unsigned int const minAmountOfDamage, unsigned int const maxAmountOfDamage, unsigned int const evasionChance,
	unsigned int const HP)
	: attackChance(attackChance), attacksPerRound(attacksPerRound), minAmountOfDamage(minAmountOfDamage), maxAmountOfDamage(maxAmountOfDamage),
	evasionChance(evasionChance), level(level), HP(HP),
	name(name)
{ }

Monster &Monster::operator=(const Monster &other)
{
	if (this != &other) {
		delete[] name;

		char buff[sizeof(other.name)];

		std::memcpy(buff, other.name, sizeof(other));
		attackChance = other.attackChance;
		attacksPerRound = other.attacksPerRound;
		minAmountOfDamage = other.minAmountOfDamage;
		maxAmountOfDamage = other.maxAmountOfDamage;
		evasionChance = other.evasionChance;
		level = other.level;
		HP = other.HP;
	}

	return *this;
}

Monster::Monster(const Monster &other)
{
	char buff[sizeof(other.name)];

	std::memcpy(buff, other.name, sizeof(other));
	name = buff;
	attackChance = other.attackChance;
	attacksPerRound = other.attacksPerRound;
	minAmountOfDamage = other.minAmountOfDamage;
	maxAmountOfDamage = other.maxAmountOfDamage;
	evasionChance = other.evasionChance;
	level = other.level;
	HP = other.HP;
}

Monster::Monster(Monster &&other) noexcept
{
	name = other.name;
	attackChance = other.attackChance;
	attacksPerRound = other.attacksPerRound;
	minAmountOfDamage = other.minAmountOfDamage;
	maxAmountOfDamage = other.maxAmountOfDamage;
	evasionChance = other.evasionChance;
	level = other.level;
	HP = other.HP;

	other.name = nullptr;
}

Monster &Monster::operator=(Monster &&other) noexcept
{
	if (this != &other) {
		delete name;

		name = other.name;
		attackChance = other.attackChance;
		attacksPerRound = other.attacksPerRound;
		minAmountOfDamage = other.minAmountOfDamage;
		maxAmountOfDamage = other.maxAmountOfDamage;
		evasionChance = other.evasionChance;
		level = other.level;
		HP = other.HP;

		other.name = nullptr;
	}

	return *this;
}

Monster::~Monster()
{
	delete[] name;
	name = nullptr;
}

int const Monster::getDamage() const
{
	std::default_random_engine generator;
	generator.seed(time(nullptr));

	int totalDamage = 0;

	std::uniform_int_distribution<int> attackChangeDistribution(getMinAmountOfDamage(), getMaxAmountOfDamage());
	int randomChange = attackChangeDistribution(generator);

	for (auto i = 0; i < randomChange; i++)
	{
		std::uniform_int_distribution<int> attackDamageDistribution(getMinAmountOfDamage(), getMaxAmountOfDamage());
		totalDamage += attackDamageDistribution(generator);
	}

	return totalDamage;
}

bool const Monster::getDefence() const
{
	std::default_random_engine generator;
	generator.seed(time(nullptr));

	std::uniform_int_distribution<int> attackChangeDistribution(0, 100);
	int randomChange = attackChangeDistribution(generator);

	return randomChange > getEvasionChance();
}
