#include "pch.h"
#include "Dungeon.h"


Dungeon::Dungeon()
{
}


Dungeon::~Dungeon()
{
}

bool Dungeon::hasTrees()
{
	return false;
}

bool Dungeon::hasWater()
{
	return false;
}

bool Dungeon::canTravel()
{
	return true;
}

list<Npc> Dungeon::getNpcs()
{
	return list<Npc>();
}

list<Item> Dungeon::getGroundItems()
{
	return list<Item>();
}

void Dungeon::removeGrounditem(int itemId)
{
}

void Dungeon::addGrounditem(Item item)
{
}

void Dungeon::removeNpc(int npcId)
{
}

void Dungeon::addNpc(int npcId)
{
}

string Dungeon::onEnterance(Player & player)
{
	return "You enter the dungeon";
}
