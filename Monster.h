#ifndef CPP1_ASSESSMENT_MONSTER_H
#define CPP1_ASSESSMENT_MONSTER_H


class Monster
{
public:
    Monster() = default;
    Monster(char *name, unsigned int level, unsigned int attackChance, unsigned int attacksPerRound,
                unsigned int minAmountOfDamage, unsigned int maxAmountOfDamage, unsigned int evasionChance,
                unsigned int HP);

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
    const char *getName() const;
    void setName(char* name);
    unsigned int getHP() const;
    void setHP(unsigned int HP);
private:
    unsigned int attackChance;
    unsigned int attacksPerRound;
    unsigned int minAmountOfDamage;
    unsigned int maxAmountOfDamage;
    unsigned int evasionChance;
    unsigned int level;
    unsigned int HP;
    char *name;
};


#endif //CPP1_ASSESSMENT_MONSTER_H
