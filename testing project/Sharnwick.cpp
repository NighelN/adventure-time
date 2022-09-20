#include "pch.h"
#include "Sharnwick.h"


Sharnwick::Sharnwick()
{
}


Sharnwick::~Sharnwick()
{
}

bool Sharnwick::hasTrees()
{
	return false;
}

bool Sharnwick::hasWater()
{
	return false;
}

bool Sharnwick::canTravel()
{
	return true;
}

list<Npc> Sharnwick::getNpcs()
{
	return list<Npc>();
}

list<Item> Sharnwick::getGroundItems()
{
	return list<Item>();
}

void Sharnwick::removeGrounditem(int itemId)
{
}

void Sharnwick::addGrounditem(Item item)
{
}

void Sharnwick::removeNpc(int npcId)
{
}

void Sharnwick::addNpc(int npcId)
{
}

string Sharnwick::onEnterance(Player & player)
{
	return "You enter Sharnwick";
}
