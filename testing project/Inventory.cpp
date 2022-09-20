#include "pch.h"
#include "Inventory.h"
#include <iostream>
#include <string>


Inventory::Inventory()
{
	this->clear();
}


Inventory::~Inventory()
{
}

void Inventory::clear()
{
	//Loops though the amount of slots the player has
	for (int index = 0; index < sizeof(this->items) / sizeof(*this->items); index++) {
		//Places an empty item in the array
		this->items[index] = Item(-1, 0);
	}
}

void Inventory::set(int slot, Item item)
{
	this->items[slot] = item;
}

void Inventory::add(Item item)
{
	//If you have no free slots to add the item
	if (this->freeSlots() <= 0) {
		cout << "You do not have any room in your inventory." << endl;
		return;
	}
	//Grabs the next free slot
	int slot = item.isStackable() && contains(item.getName()) ? getSlot(item.getId()) : getNextFreeSlot();
	//Checks if the item is stackable
	if (item.isStackable()) {
		//Sets the amount
		item.setAmount(item.getAmount() + this->items[slot].getAmount());
		//Edits the item based on slot
		this->set(slot, item);
	}
	//If the item is not stackable
	else {
		//Loops through how many items its trying to add
		for (int i = 0; i < item.getAmount(); i++) {
			//Grabs the next free slot
			int slot = getNextFreeSlot();
			//Edits the item based on slot
			this->set(slot, item);
		}
	}
}

void Inventory::add(Item item, int slot)
{
	//Edits the item based on slot
	this->set(slot, item.getId());
}

void Inventory::remove(Item item)
{
	//Grabs the slot the item is in
	int slot = getSlot(item.getId());
	//Amount your trying to remove
	int amount = item.getAmount();
	//Id your trying to remove
	int id = item.getId();
	//Checks if the item is stackable
	if (item.isStackable()) {
		//Checks if it should remove the item
		if (amount == this->items[slot].getAmount()) {
			//Removes the item
			this->set(slot, Item(-1));
		}
		//Edits the item based on slot
		else {
			this->set(slot, Item(item.getId(), this->items[slot].getAmount() - amount));
		}
	}
	else {
		//Loops through how many items its trying to remove
		for (int i = 0; i < item.getAmount(); i++) {
			//Grabs the slot for the item
			int slot = this->getSlot(item.getId());
			//Edits the item based on slot
			this->set(slot, Item(-1));
		}
	}
}

bool Inventory::contains(string itemName)
{
	bool contains = false;
	//Loops though all items the player has in his inventory
	for (Item item : this->items) {
		//Checks if the name match
		if (item.getName() == itemName) {
			//Says it contains the inventory
			contains = true;
			//Break the loop
			break;
		}
	}
	return contains;
}

bool Inventory::contains(string name, int amount)
{
	bool contains = false;
	//Loops though all items the player has in his inventory
	for (Item item : this->items) {
		//Checks if the name match and amount you have is more then needed
		if (item.getName() == name && item.getAmount() >= amount) {
			//Says it contains the inventory
			contains = true;
			//Break the loop
			break;
		}
	}
	return contains;
}

int Inventory::getNextFreeSlot()
{
	
	//The slot its currently at
	int slot = 0;
	//Loops though all items the player has in his inventory
	for (Item item : this->items) {
		//If the slot is not empty skip.
		if (item.getId() != -1) {
			//Increase slot
			slot++;
			continue;
		}
		//Found an empty slot so break the loop
		else {
			break;
		}
	}
	return slot;
}

int Inventory::getSlot(int itemId)
{
	//The slot its currently at
	int slot = 0;
	//Loops though all items the player has in his inventory
	for (Item item : this->items) {
		//If the slot is empty skip it
		if (item.getId() == -1) {
			//Increase slot
			slot++;
			continue;
		}
		//If the item's id equals the parameter itemId break out of the loop
		if (item.getId() == itemId) {
			break;
		}
		//Increase slot
		slot++;
	}
	return slot;
}

int Inventory::freeSlots()
{
	int freeSlots = 0;
	//Loops though all items
	for (Item item : this->items) {
		//If item isnt -1 continue
		if(item.getId() != -1) {
			continue;
		}
		//Add to the free slots
		freeSlots++;
	}
	return freeSlots;
}

void Inventory::printInventory()
{
	//Checks if the player has 0 items
	if (this->freeSlots() == 28) {
		cout << "Your inventory is empty." << endl << endl;
		return;
	}
	//Current slot its showing
	int slot = 0;
	//Tells the user hes looking at his inventory
	cout << "Your inventory:" << endl;
	//Loop though all items
	for (Item item : this->items) {
		//If item id is -1 skip it
		if (item.getId() == -1) continue;
		//Checks if the item is not stackable
		if (!item.isStackable()) {
			cout << "Slot[" << slot << "] Name[" << item.getName() << "]" << endl;
		}
		//If item is stackable
		else {
			cout << "Slot[" << slot << "] Name[" << item.getName() << "] Amount[" << item.getAmount() << "]" << endl << endl;
		}
		//Increase the slot
		slot++;
	}
}
