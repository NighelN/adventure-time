#include "pch.h"
#include "Dungeon_One.h"


Dungeon_One::Dungeon_One()
{
	int monsters[4] = { 10, 11, 12, 13 };
	//Loops though all monsters for this dungeon
	for (int index = 0; index < sizeof(monsters) / sizeof(*monsters); index++) {
		//Adds monsters to the dungeon
		npcs.push_back(Npc(monsters[index]));
	}
}


Dungeon_One::~Dungeon_One()
{
}

bool Dungeon_One::hasTrees()
{
	return false;
}

bool Dungeon_One::hasWater()
{
	return false;
}

bool Dungeon_One::canTravel()
{
	return true;
}

list<Npc> Dungeon_One::getNpcs()
{
	return npcs;
}

list<Item> Dungeon_One::getGroundItems()
{
	return groundItems;
}

void Dungeon_One::removeGrounditem(int itemId)
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

void Dungeon_One::addGrounditem(Item item)
{
	this->groundItems.push_back(item);
}

void Dungeon_One::removeNpc(int npcId)
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

void Dungeon_One::addNpc(int npcId)
{
	this->npcs.push_back(Npc(npcId));
}

string Dungeon_One::onEnterance(Player & player)
{
	return "You enter the dungeon";
}
