#include "pch.h"
#include "Path.h"


Path::Path()
{
}


Path::~Path()
{
}

bool Path::hasTrees()
{
	return false;
}

bool Path::hasWater()
{
	return false;
}

bool Path::canTravel()
{
	return true;
}

list<Npc> Path::getNpcs()
{
	return list<Npc>();
}

list<Item> Path::getGroundItems()
{
	return list<Item>();
}

void Path::removeGrounditem(int itemId)
{
}

void Path::addGrounditem(Item item)
{
}

void Path::removeNpc(int npcId)
{
}

void Path::addNpc(int npcId)
{
}

string Path::onEnterance(Player & player)
{
	return "";
}
