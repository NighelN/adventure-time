#pragma once
#include "Maps.h"
#include "TextHandler.h"

class Mensfield : public Maps
{
public:
	Mensfield();
	~Mensfield();
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
