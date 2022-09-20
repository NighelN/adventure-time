#include "pch.h"
#include "FishingStore.h"


FishingStore::FishingStore()
{
	//Adds the Fisherman clerk to the store
	npcs.push_back(Npc("Fisherman clerk"));
}


FishingStore::~FishingStore()
{
}

bool FishingStore::hasTrees()
{
	return false;
}

bool FishingStore::hasWater()
{
	return false;
}

bool FishingStore::canTravel()
{
	return true;
}

list<Npc> FishingStore::getNpcs()
{
	return npcs;
}

list<Item> FishingStore::getGroundItems()
{
	return list<Item>();
}

void FishingStore::removeGrounditem(int itemId)
{
}

void FishingStore::addGrounditem(Item item)
{
}

void FishingStore::removeNpc(int npcId)
{
}

void FishingStore::addNpc(int npcId)
{
}

string FishingStore::onEnterance(Player & player)
{
	return "You enter the fishing store, you are welcomed by the fisherman clerk";
}
