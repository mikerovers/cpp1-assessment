#pragma once

class Monster
{
public:
	Monster() = default;
	Monster(const char *name, unsigned int const level, unsigned int const attackChance, unsigned int const attacksPerRound,
		unsigned int const minAmountOfDamage, unsigned int const maxAmountOfDamage, unsigned int const evasionChance,
		unsigned int const HP);
	~Monster();

	int const getDamage() const;
	bool const getDefence() const;

	Monster&operator=(const Monster& other);
	Monster(const Monster& other);
	Monster(Monster&& other) noexcept;
	Monster&operator=(Monster&& other) noexcept;

	unsigned int const getAttackChance() const;
	void setAttackChance(unsigned int const attackChance);
	unsigned int const getAttacksPerRound() const;
	void setAttacksPerRound(unsigned int const attacksPerRound);
	unsigned int const getMinAmountOfDamage() const;
	void setMinAmountOfDamage(unsigned int const minAmountOfDamage);
	unsigned int const getMaxAmountOfDamage() const;
	void setMaxAmountOfDamage(unsigned int  constmaxAmountOfDamage);
	unsigned int const getEvasionChance() const;
	void setEvasionChance(unsigned int  constevasionChance);
	unsigned int const getLevel() const;
	void setLevel(unsigned int const level);
	const char* const getName() const;
	void setName(const char* nam);
	int const getHP() const;
	void setHP(const int HP);
private:
	unsigned int attackChance;
	unsigned int attacksPerRound;
	unsigned int minAmountOfDamage;
	unsigned int maxAmountOfDamage;
	unsigned int evasionChance;
	unsigned int level;
	int HP;
	const char* name;
};
