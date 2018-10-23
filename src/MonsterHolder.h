#pragma once
class MonsterHolder
{
private:
	class Monster** _monsters;
public:
	MonsterHolder();
	~MonsterHolder();

	void Init();
	void AddMonster(Monster* monster, int index);
	class Monster** GetMonsters();
};

