#include "pch.h"
#include "Tutorial.h"
#include <iostream>

using namespace std;

Tutorial::Tutorial()
{
	//Adds an Fishing rod to the ground items
	this->groundItems.push_back(Item("Fishing rod"));
	//Adds an Fishing bait to the ground items
	this->groundItems.push_back(Item("Fishing bait", 2));
	//Adds an Axe to the ground items
	this->groundItems.push_back(Item("Axe"));
	//Adds an Tinderbox to the ground items
	this->groundItems.push_back(Item("Tinderbox"));

	//Adds the guide to the tutorial map
	npcs.push_back(Npc(0));
	//Adds the rat to the tutorial map
	npcs.push_back(Npc(1));
}


Tutorial::~Tutorial()
{
}

bool Tutorial::hasTrees()
{
	return true;
}

bool Tutorial::hasWater()
{
	return true;
}

bool Tutorial::canTravel()
{
	return true;
}

list<Npc> Tutorial::getNpcs()
{
	return this->npcs;
}

list<Item> Tutorial::getGroundItems()
{
	return this->groundItems;
}

void Tutorial::removeGrounditem(int itemId)
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

void Tutorial::addGrounditem(Item item)
{
	this->groundItems.push_back(item);
}

void Tutorial::removeNpc(int npcId)
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

void Tutorial::addNpc(int npcId)
{
}

string Tutorial::onEnterance(Player& player)
{
	return player.tutorialStage >= 14 ? "You enter the place where you woke up." : "As you wake up you notice your on a strange island, you don't feel good.\nMaybe i should look around....\n";
}
