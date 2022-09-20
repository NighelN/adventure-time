#include "pch.h"
#include "Ironforge.h"


Ironforge::Ironforge()
{
}


Ironforge::~Ironforge()
{
}

bool Ironforge::hasTrees()
{
	return false;
}

bool Ironforge::hasWater()
{
	return false;
}

bool Ironforge::canTravel()
{
	return true;
}

list<Npc> Ironforge::getNpcs()
{
	return list<Npc>();
}

list<Item> Ironforge::getGroundItems()
{
	return list<Item>();
}

void Ironforge::removeGrounditem(int itemId)
{
}

void Ironforge::addGrounditem(Item item)
{
}

void Ironforge::removeNpc(int npcId)
{
}

void Ironforge::addNpc(int npcId)
{
}

string Ironforge::onEnterance(Player & player)
{
	return "You enter Ironforge";
}
