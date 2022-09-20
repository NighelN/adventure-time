#include "pch.h"
#include "Dungeon_Two.h"


Dungeon_Two::Dungeon_Two()
{
}


Dungeon_Two::~Dungeon_Two()
{
}

bool Dungeon_Two::hasTrees()
{
	return false;
}

bool Dungeon_Two::hasWater()
{
	return false;
}

bool Dungeon_Two::canTravel()
{
	return true;
}

list<Npc> Dungeon_Two::getNpcs()
{
	return npcs;
}

list<Item> Dungeon_Two::getGroundItems()
{
	return groundItems;
}

void Dungeon_Two::removeGrounditem(int itemId)
{
	//Loops though the list
	for (list<Item>::iterator it = groundItems.begin(); it != this->groundItems.end(); it++) {
		//Checks if the ids match
		if (it->getId() == itemId) {
			//Remove the ground item
			this->groundItems.erase(it);
			break;
		}
	}
}

void Dungeon_Two::addGrounditem(Item item)
{
	this->groundItems.push_back(item);
}

void Dungeon_Two::removeNpc(int npcId)
{
	//Loops though the list
	for (list<Npc>::iterator it = npcs.begin(); it != this->npcs.end(); it++) {
		//Checks if the ids match
		if (it->getId() == npcId) {
			//Remove the ground item
			this->npcs.erase(it);
			break;
		}
	}
}

void Dungeon_Two::addNpc(int npcId)
{
	this->npcs.push_back(Npc(npcId));
}

string Dungeon_Two::onEnterance(Player & player)
{
	return "You enter the dungeon";
}
