#pragma once
#include <string>

using namespace std;

class Npc
{
private:
	int id;
	int health;
public:
	Npc();
	Npc(int id);
	Npc(string name);
	~Npc();
	int getId(string name);
	int getHealth();
	void setHealth(int health);
	int getId();
	string getName();
	int baseHealth();
	bool isAttackable();
	int getDamage();
};

