#include "pch.h"
#include "FishingDock.h"


FishingDock::FishingDock()
{
}


FishingDock::~FishingDock()
{
}

bool FishingDock::hasTrees()
{
	return false;
}

bool FishingDock::hasWater()
{
	return true;
}

bool FishingDock::canTravel()
{
	return true;
}

list<Npc> FishingDock::getNpcs()
{
	return list<Npc>();
}

list<Item> FishingDock::getGroundItems()
{
	return list<Item>();
}

void FishingDock::removeGrounditem(int itemId)
{
}

void FishingDock::addGrounditem(Item item)
{
}

void FishingDock::removeNpc(int npcId)
{
}

void FishingDock::addNpc(int npcId)
{
}

string FishingDock::onEnterance(Player & player)
{
	return "";
}
