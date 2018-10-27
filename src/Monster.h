#pragma once

class Monster
{
public:
	Monster() = default;
	Monster(const char *name, unsigned int level, unsigned int attackChance, unsigned int attacksPerRound,
		unsigned int minAmountOfDamage, unsigned int maxAmountOfDamage, unsigned int evasionChance,
		unsigned int HP);
	~Monster();

	Monster&operator=(const Monster& other);
	Monster(const Monster& other);
	Monster(Monster&& other) noexcept;
	Monster&operator=(Monster&& other) noexcept;

	unsigned int getAttackChance() const;
	void setAttackChance(unsigned int attackChance);
	unsigned int getAttacksPerRound() const;
	void setAttacksPerRound(unsigned int attacksPerRound);
	unsigned int getMinAmountOfDamage() const;
	void setMinAmountOfDamage(unsigned int minAmountOfDamage);
	unsigned int getMaxAmountOfDamage() const;
	void setMaxAmountOfDamage(unsigned int maxAmountOfDamage);
	unsigned int getEvasionChance() const;
	void setEvasionChance(unsigned int evasionChance);
	unsigned int getLevel() const;
	void setLevel(unsigned int level);
	const char* getName() const;
	void setName(const char* nam);
	unsigned int getHP() const;
	void setHP(const unsigned int HP);
private:
	unsigned int attackChance;
	unsigned int attacksPerRound;
	unsigned int minAmountOfDamage;
	unsigned int maxAmountOfDamage;
	unsigned int evasionChance;
	unsigned int level;
	unsigned int HP;
	const char* name;
};
