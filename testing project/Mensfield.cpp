#include "pch.h"
#include "Mensfield.h"


Mensfield::Mensfield()
{
	//Adds 25 coins to the main town on boot
	this->groundItems.push_back(Item("Coins", 25));
	//Adds a man to the main town
	this->npcs.push_back(Npc("Man"));
	//Adds a women to the main town
	this->npcs.push_back(Npc("Women"));
}


Mensfield::~Mensfield()
{
}

bool Mensfield::hasTrees()
{
	return false;
}

bool Mensfield::hasWater()
{
	return false;
}

bool Mensfield::canTravel()
{
	return true;
}

list<Npc> Mensfield::getNpcs()
{
	return npcs;
}

list<Item> Mensfield::getGroundItems()
{
	return groundItems;
}

void Mensfield::removeGrounditem(int itemId)
{
}

void Mensfield::addGrounditem(Item item)
{
}

void Mensfield::removeNpc(int npcId)
{
}

void Mensfield::addNpc(int npcId)
{
}

string Mensfield::onEnterance(Player& player)
{
	return "You enter mensfield";
}