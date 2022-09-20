#pragma once
#include "Maps.h"
#include <string>

class Tutorial : public Maps
{
public:
	Tutorial();
	~Tutorial();
	list<Item> groundItems;
	list<Npc> npcs;
	bool hasTrees() override;
	bool hasWater() override;
	bool canTravel() override;
	list<Npc> getNpcs() override;
	list<Item> getGroundItems() override;
	void removeGrounditem(int itemId) override;
	void addGrounditem(Item item) override;
	void removeNpc(int npcId) override;
	void addNpc(int npcId) override;
	string onEnterance(Player& player) override;
};

