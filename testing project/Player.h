#pragma once
#include <string>
#include "Inventory.h"

using namespace std;

class Player
{
private:
	Inventory inventory;
	int playerHealth = 10;
	int x = 0, y = 0;
public:
	int quests[2];
	int tutorialStage = 0;
	bool skipTutorial;
	bool hasFire;
	bool inCombat;
	string playerName;
	string gender;
	Player();
	~Player();
	void clear();
	Inventory& getInventory();
	void setHealth(int health);
	int getHealth();
	int getX();
	int getY();
	void move(int x, int y);
	int getDamage(string weapon);
};

