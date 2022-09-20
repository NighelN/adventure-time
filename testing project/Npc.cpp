#include "pch.h"
#include "Npc.h"


Npc::Npc()
{
}

Npc::Npc(int id)
{
	this->id = id;
	this->health = this->baseHealth();
}

Npc::Npc(string name) {
	this->id = getId(name);
	this->health = this->baseHealth();
}


Npc::~Npc()
{
}

int Npc::getId(string name) {
	if (name == "Guide")
		return 0;
	else if (name == "Rat")
		return 1;
	else if (name == "Priest")
		return 2;
	else if (name == "Fishermen")
		return 3;
	else if (name == "Captain")
		return 4;
	else if (name == "Man")
		return 5;
	else if (name == "Women")
		return 6;
	else if (name == "Medicine clerk")
		return 7;
	else if (name == "Fisherman clerk")
		return 8;
	else if (name == "Blacksmith")
		return 9;
	else if (name == "Skeleton")
		return 10;
	else if (name == "Zombie")
		return 11;
	else if (name == "Troll")
		return 12;
	else if (name == "Ogre")
		return 13;
	else if (name == "Dragon")
		return 14;
	return -1;
}

int Npc::getHealth()
{
	return this->health;;
}

void Npc::setHealth(int health)
{
	this->health = health;
}

int Npc::getId()
{
	return this->id;
}

string Npc::getName()
{
	switch (this->id) {
		case 0:
			return "Guide";
		case 1:
			return "Rat";
		case 2:
			return "Priest";
		case 3:
			return "Fishermen";
		case 4:
			return "Captain";
		case 5:
			return "Man";
		case 6:
			return "Women";
		case 7:
			return "Medicine clerk";
		case 8:
			return "Fisherman clerk";
		case 9:
			return "Blacksmith";
		case 10:
			return "Skeleton";
		case 11:
			return "Zombie";
		case 12:
			return "Troll";
		case 13:
			return "Ogre";
		case 14:
			return "Dragon";
		default:
			return "Npc does not exist.";
	}
}

int Npc::baseHealth()
{
	switch (this->id) {
		case 1: //Rat
			return 3;
		case 10: //Skeleton
			return 5;
		case 11: //Zombie
			return 8;
		case 12: //Troll
			return 7;
		case 13: //Ogre
			return 10;
		case 14: //Ogre
			return 15;
		default:
			return 0;
	}
}

bool Npc::isAttackable()
{
	switch (this->id) {
		case 1: //Rat
		case 10: //Skeleton
		case 11: //Zombie
		case 12: //Troll
		case 13: //Ogre
		case 14: //Dragon
			return true;
		default:
			return false;
	}
}

int Npc::getDamage()
{
	switch (this->id) {
		case 1: //Rat
			return 1;
		case 10: //Skeleton
			return 2;
		case 11: //Zombie
			return 2;
		case 12: //Troll
			return 3;
		case 13: //Ogre
			return 4;
		case 14: //Dragon
			return 8;
		default:
			return 0;
	}
}
