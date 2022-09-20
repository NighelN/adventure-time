#pragma once
#include "Player.h"
#include "Npc.h"
#include "Item.h"
#include <string>
#include <list>

using namespace std;

class Maps
{
public:
	Maps(void) {};
	~Maps(void) {};
	bool virtual hasTrees() = 0;
	bool virtual hasWater() = 0;
	bool virtual canTravel() = 0;
	list<Npc> virtual getNpcs() = 0;
	list<Item> virtual getGroundItems() = 0;
	void virtual removeGrounditem(int itemId) = 0;
	void virtual addGrounditem(Item item) = 0;
	void virtual removeNpc(int npcId) = 0;
	void virtual addNpc(int npcId) = 0;
	string virtual onEnterance(Player& player) = 0;
};

