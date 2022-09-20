#include "pch.h"
#include "Empty.h"


Empty::Empty()
{
}


Empty::~Empty()
{
}

bool Empty::hasTrees()
{
	return false;
}

bool Empty::hasWater()
{
	return false;
}

bool Empty::canTravel()
{
	return false;
}

list<Npc> Empty::getNpcs()
{
	list<Npc> npcs;

	return npcs;
}

list<Item> Empty::getGroundItems()
{
	list<Item> groundItems;

	return groundItems;
}

void Empty::removeGrounditem(int itemId)
{
}

void Empty::addGrounditem(Item item)
{
}

void Empty::removeNpc(int npcId)
{
}

void Empty::addNpc(int npcId)
{
}

string Empty::onEnterance(Player& player)
{
	return "This is an empty space";
}
