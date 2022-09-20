#include "pch.h"
#include "Item.h"

void Item::setAmount(int amount) {
	this->amount = amount;
}

int Item::getAmount() {
	return this->amount;
}

void Item::setId(int id) {
	this->id = id;
}

int Item::getId() {
	return this->id;
}

Item::Item()
{
}

Item::Item(int id)
{
	this->id = id;
	this->amount = 1;
}

Item::Item(int id, int amount)
{
	this->id = id;
	this->amount = amount;
}

Item::Item(string itemName)
{
	this->id = this->getId(itemName);
	this->amount = 1;
}

Item::Item(string itemName, int amount)
{
	this->id = this->getId(itemName);
	this->amount = amount;
}

Item::~Item()
{
}

string Item::getName()
{
	switch (this->id) {
		case 0:
			return "Sword";
		case 1:
			return "Axe";
		case 2:
			return "Log";
		case 3:
			return "Tinderbox";
		case 4:
			return "Fishing rod";
		case 5:
			return "Fishing bait";
		case 6:
			return "Raw fish";
		case 7:
			return "Cooked fish";
		case 8:
			return "Burned fish";
		case 9:
			return "Knife";
		case 10:
			return "Coins";
		case 11:
			return "Medicine";
		case 12:
			return "Wooden sword";
		case 13:
			return "Stone sword";
		case 14:
			return "Broken shield";
		case 15:
			return "Sword of immense power";
		default:
			return "Item does not exist";
	}
}

int Item::getId(string itemName)
{
	if (itemName == "Sword")
		return 0;
	else if (itemName == "Axe")
		return 1;
	else if (itemName == "Log")
		return 2;
	else if (itemName == "Tinderbox")
		return 3;
	else if (itemName == "Fishing rod")
		return 4;
	else if (itemName == "Fishing bait")
		return 5;
	else if (itemName == "Raw fish")
		return 6;
	else if (itemName == "Cooked fish")
		return 7;
	else if (itemName == "Burned fish")
		return 8;
	else if (itemName == "Knife")
		return 9;
	else if (itemName == "Coins")
		return 10;
	else if (itemName == "Medicine")
		return 11;
	else if (itemName == "Wooden sword")
		return 12;
	else if (itemName == "Stone sword")
		return 13;
	else if (itemName == "Broken shield")
		return 14;
	else if (itemName == "Sword of immense power")
		return 15;
	else
		return -1;
}

bool Item::isStackable()
{
	switch (this->id) {
		case 5:
		case 10:
			return true;
	}
	return false;
}

int Item::getPrice()
{
	switch (this->id) {
		case 3: //Tinderbox
			return 5;
		case 11: //Medicine
			return 25;
		case 4: //Fishing rod
			return 10;
		case 5: //Fishing bait
			return 5;
		case 6: //Raw fish
			return 10;
		case 1: //Axe
			return 15;
		case 12: //Wooden sword
			return 30;
		case 13: //Stone sword
			return 50;
		default:
			return 0;
	}
}
