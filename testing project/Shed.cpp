#include "pch.h"
#include "Shed.h"


Shed::Shed()
{
	//Pushes back the priest
	npcs.push_back(Npc("Priest"));
}


Shed::~Shed()
{
}

bool Shed::hasTrees()
{
	return false;
}

bool Shed::hasWater()
{
	return false;
}

bool Shed::canTravel()
{
	return true;
}

list<Npc> Shed::getNpcs()
{
	return npcs;
}

list<Item> Shed::getGroundItems()
{
	return list<Item>();
}

void Shed::removeGrounditem(int itemId)
{
}

void Shed::addGrounditem(Item item)
{
}

void Shed::removeNpc(int npcId)
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

void Shed::addNpc(int npcId)
{
}

string Shed::onEnterance(Player & player)
{
	return "You enter an abandoned shed.";
}
