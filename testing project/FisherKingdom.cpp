#include "pch.h"
#include "FisherKingdom.h"


FisherKingdom::FisherKingdom()
{
}


FisherKingdom::~FisherKingdom()
{
}

bool FisherKingdom::hasTrees()
{
	return false;
}

bool FisherKingdom::hasWater()
{
	return false;
}

bool FisherKingdom::canTravel()
{
	return true;
}

list<Npc> FisherKingdom::getNpcs()
{
	return list<Npc>();
}

list<Item> FisherKingdom::getGroundItems()
{
	return list<Item>();
}

void FisherKingdom::removeGrounditem(int itemId)
{
}

void FisherKingdom::addGrounditem(Item item)
{
}

void FisherKingdom::removeNpc(int npcId)
{
}

void FisherKingdom::addNpc(int npcId)
{
}

string FisherKingdom::onEnterance(Player & player)
{
	return "You enter the fishing kingdom";
}
