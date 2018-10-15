#include <cstring>
#include <iostream>
#include "Monster.h"

unsigned int Monster::getAttackChance() const
{
    return attackChance;
}

void Monster::setAttackChance(unsigned int attackChance)
{
    Monster::attackChance = attackChance;
}

unsigned int Monster::getAttacksPerRound() const
{
    return attacksPerRound;
}

void Monster::setAttacksPerRound(unsigned int attacksPerRound)
{
    Monster::attacksPerRound = attacksPerRound;
}

unsigned int Monster::getMinAmountOfDamage() const
{
    return minAmountOfDamage;
}

void Monster::setMinAmountOfDamage(unsigned int minAmountOfDamage)
{
    Monster::minAmountOfDamage = minAmountOfDamage;
}

unsigned int Monster::getMaxAmountOfDamage() const
{
    return maxAmountOfDamage;
}

void Monster::setMaxAmountOfDamage(unsigned int maxAmountOfDamage)
{
    Monster::maxAmountOfDamage = maxAmountOfDamage;
}

unsigned int Monster::getEvasionChance() const
{
    return evasionChance;
}

void Monster::setEvasionChance(unsigned int evasionChance)
{
    Monster::evasionChance = evasionChance;
}

unsigned int Monster::getLevel() const
{
    return level;
}

void Monster::setLevel(unsigned int level)
{
    Monster::level = level;
}

const char *Monster::getName() const
{
    return name;
}

void Monster::setName(char *name)
{
    Monster::name = name;
}

unsigned int Monster::getHP() const
{
    return HP;
}

void Monster::setHP(unsigned int HP)
{
    Monster::HP = HP;
}

Monster::Monster(char *name, unsigned int level, unsigned int attackChance, unsigned int attacksPerRound,
                 unsigned int minAmountOfDamage, unsigned int maxAmountOfDamage, unsigned int evasionChance,
                 unsigned int HP)
                 : name(name), level(level), attackChance(attackChance), attacksPerRound(attacksPerRound),
                   minAmountOfDamage(minAmountOfDamage), maxAmountOfDamage(maxAmountOfDamage), evasionChance(evasionChance),
                   HP(HP)
{ }

Monster &Monster::operator=(const Monster &other)
{
    if (this != &other) {
        delete[] name;

        name = new char[sizeof(other) + 1];
        strncpy(name, other.name, sizeof(other));
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
    name = new char[strlen(other.name)];

    std::strcpy(name, other.name);
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
    delete name;
}
