#pragma once
#include "Item.h"

using namespace std;

class Inventory
{
private:
public:
	Inventory();
	~Inventory();
	Item items[28];
	void clear();
	void set(int slot, Item item);
	void add(Item item);
	void add(Item item, int slot);
	void remove(Item item);
	bool contains(string name); 
	bool contains(string name, int amount);
	int getNextFreeSlot();
	int getSlot(int itemId);
	int freeSlots();
	void printInventory();
};

