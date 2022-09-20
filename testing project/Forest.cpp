#include "pch.h"
#include "Forest.h"


Forest::Forest()
{
}


Forest::~Forest()
{
}

bool Forest::hasTrees()
{
	return true;
}

bool Forest::hasWater()
{
	return false;
}

bool Forest::canTravel()
{
	return true;
}

list<Npc> Forest::getNpcs()
{
	return list<Npc>();
}

list<Item> Forest::getGroundItems()
{
	return list<Item>();
}

void Forest::removeGrounditem(int itemId)
{
}

void Forest::addGrounditem(Item item)
{
}

void Forest::removeNpc(int npcId)
{
}

void Forest::addNpc(int npcId)
{
}

string Forest::onEnterance(Player & player)
{
	return "";
}
