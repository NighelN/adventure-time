#include "pch.h"
#include "MedicineStore.h"


MedicineStore::MedicineStore()
{
	//Adds the clerk to the medicine store
	npcs.push_back(Npc("Medicine clerk"));
}


MedicineStore::~MedicineStore()
{
}

bool MedicineStore::hasTrees()
{
	return false;
}

bool MedicineStore::hasWater()
{
	return false;
}

bool MedicineStore::canTravel()
{
	return true;
}

list<Npc> MedicineStore::getNpcs()
{
	return npcs;
}

list<Item> MedicineStore::getGroundItems()
{
	return list<Item>();
}

void MedicineStore::removeGrounditem(int itemId)
{
}

void MedicineStore::addGrounditem(Item item)
{
}

void MedicineStore::removeNpc(int npcId)
{
}

void MedicineStore::addNpc(int npcId)
{
}

string MedicineStore::onEnterance(Player & player)
{
	return "You enter the Medicine store.";
}
