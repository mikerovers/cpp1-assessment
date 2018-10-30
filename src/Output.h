#pragma once
#include <iostream>
#include "BaseRoom.h"
#include "Dungeon.h"
#include "Inventory.h"

class Game;

class Output {
public:
	Output();
	~Output();
	void ShowIntroduction() const;
	void ShowMap(Dungeon* const dungeon, int const currentLevel) const;
	void ShowFalseCommand() const;
	void ClearScreen() const;
	void ShowCommands() const;
	void AskForDungeonWidth() const;
	void AskForDungeonHeight() const;
	void AskForDungeonDepth() const;
	void ShowGameStarted() const;
	void PrintInventory(const Inventory* const inventory) const;
	void PrintItemUsed(Item* const item) const;
	void PrintNothingHappened(const Item* const item) const;
	void AskForItem() const;
	void PrintHealthIncrease(int const amount) const;
	void ShowRoomDescription(BaseRoom* const room) const;
	void ShowExits(BaseRoom* const room) const;
	void ShowEnemies(Monster* const monster) const;
	void BlankLine() const;
	void ShowOptions() const;
	void ShowItem(const Item* const item) const;
	void ShowPickedUpItem(const Item* const item) const;
	void PrintPlayerDeath(const Monster* monster, const Inventory* const inventory, Game* const game) const;
	void PrintStartCombat(const Monster* monster) const;
	void PrintVictory(const Player* const player, const Monster* const monster) const;
	void AskLoadPlayer();
	void PrintLoadingError();
	void ShowLoaded(bool const newPlayer) const;
	void PrintAttackEvaded(const Monster* const monster) const;
	void PrintSuccessfullAttack(Monster* const monster, int const damage) const;
	void PrintMonsterAttack(Monster* const monster, int const damage);
	void PrintPlayerEvaded(const Monster* const monster) const;
	void PrintPlayerInfo(const Game* const game) const;
	void PrintRestNotAvailable() const;
	void PrintRest(int const health, bool const attacked) const;
	void NoMonsterToFight() const;
	void LevelUp(int const level, int const skillpoints) const;
	void ShowExperienceGain(int const level) const;
	void ShowNoSkillpoints() const;
	void ShowAttackStatImproved(int const attack);
	void ShowGameWon(Game* const game) const;
	void ShowMoveStairs(bool const up) const;
};
