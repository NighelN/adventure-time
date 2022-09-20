#pragma once
#include <string>

using namespace std;

class Item
{
private:
	int id;
	int amount;
	bool stackable;
public:
	//Used for setting the amount of the item
	void setAmount(int amount);
	//Used for grabbing the amount of the item
	int getAmount();
	//Sets the item id
	void setId(int id);
	//Grabs the item id
	int getId();
	Item();
	~Item();
	//Used for generating an item with just an id, will automaticlly set the amount to 1
	Item(int id);
	//Used for generating an item with an id and an set amount
	Item(int id, int amount);
	//Used for generating an item with just an id, will automaticlly set the amount to 1
	Item(string itemName);
	//Used for generating an item with an id and an set amount
	Item(string itemName, int amount);
	//Gets the name of an item
	string getName();
	//Gets the item id based on name
	int getId(string itemName);
	//Gets if an item is stackable
	bool isStackable();
	//Gets the price of an item
	int getPrice();
};

