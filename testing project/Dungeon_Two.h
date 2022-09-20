#pragma once
#include "Maps.h"

class Dungeon_Two : public Maps
{
public:
	Dungeon_Two();
	~Dungeon_Two();

	list<Npc> npcs;
	list<Item> groundItems;
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

