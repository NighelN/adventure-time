#include "pch.h"
#include "WeaponStore.h"


WeaponStore::WeaponStore()
{
	//Adds the Blacksmith to the store
	npcs.push_back(Npc("Blacksmith"));
}


WeaponStore::~WeaponStore()
{
}

bool WeaponStore::hasTrees()
{
	return false;
}

bool WeaponStore::hasWater()
{
	return false;
}

bool WeaponStore::canTravel()
{
	return true;
}

list<Npc> WeaponStore::getNpcs()
{
	return npcs;
}

list<Item> WeaponStore::getGroundItems()
{
	return list<Item>();
}

void WeaponStore::removeGrounditem(int itemId)
{
}

void WeaponStore::addGrounditem(Item item)
{
}

void WeaponStore::removeNpc(int npcId)
{
}

void WeaponStore::addNpc(int npcId)
{
}

string WeaponStore::onEnterance(Player & player)
{
	return "You enter the weapon store and you are greeted by the blacksmith";
}
