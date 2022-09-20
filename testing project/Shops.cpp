#include "pch.h"
#include "Shops.h"

list<Item> stock;
bool inShop;
string input;
int price;

void openShop(Player& player, int npcId)
{
	//Sets in shop to true
	inShop = true;
	//Clears the stock of the shop
	stock.clear();
	switch (npcId) {
		case 7:
			//Adds medicine to the store
			stock.push_back(Item("Medicine"));
			break;
		case 8:
			//Adds tinderbox to the store
			stock.push_back(Item("Tinderbox", 100));
			//Adds fishing rod to the store
			stock.push_back(Item("Fishing rod"));
			//Adds fishing bait to the store
			stock.push_back(Item("Fishing bait", 1000));
			//Adds raw fish to the store
			stock.push_back(Item("Raw fish", 100));
			break;
		case 9:
			//Adds the axe to the store
			stock.push_back(Item("Axe"));
			//Adds the wooden sword to the store
			stock.push_back(Item("Wooden sword"));
			//Adds the stone sword to the store
			stock.push_back(Item("Stone sword"));
			break;
	}
	handleInput(player);
}

void handleInput(Player& player) {
	//Stock string
	string output;
	//Current index
	int index = 0;
	for (Item item : stock) {
		output += (item.getName() + ", Price: " + to_string(item.getPrice()));
		//If its not the end of the loop add a new line
		if (index != stock.size() - 1)
			output += "\n";
		index++;
	}
	//Displays the shops stock
	handleOutput("Current stock:\n" + output + "\n\nWhat would you like to do, buy an item or leave the shop", true);
	//Keeps running while its in shop
	do {
		//Reads the input
		getline(cin, input);
		//Turns all letters to lower case so the user can type 'Yes' or 'yes'
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		//Leaves the shop
		if (input == "leave") {
			//Tells the user he leaves the shop
			handleOutput("You leave the shop.", true);
			//Sets the shop to falsae
			inShop = false;
		}
		//Checks if the input 
		else if (input.rfind("buy") == 0) {
			//Checks if there is extra stuff behind the buy
			if (input != "buy") {
				//Reads the action behind the buy
				string beginCommand = "buy", action = input.substr(beginCommand.length() + 1);
				//Checks if the item your trying to buy exists
				if (exists(action)) {
					//Sets price
					price = getPrice(action);
					//Checks if the player has the right amount of coins
					if (player.getInventory().contains("Coins", price)) {
						//Removes the item from the stock, removes the coins from the inventory and gives the right item
						remove(player, action);
						//Gives the user feedback
						handleOutput("You succesfully buy the "+ action +" for "+ to_string(price) +" coins.", true);
						//If the user buys medicine
						if (action == "medicine") {
							//Sets the stage of the quest to 4
							player.quests[0] = 4;
						}
					}
					//Does not have the right amount of coins
					else {
						handleOutput("You need atleast "+ to_string(price) +" coins to buy this item.", true);
					}
				}
				//If item does not exists in the shop
				else {
					handleOutput("Item does not exists in the store.", true);
				}
			}
			//If there is no right input after buy
			else {
				handleOutput("Please fill in the item your trying to buy.", true);
			}
		}
		//No right input
		else {
			handleOutput("Wrong input please use buy 'itemname' or leave.", true);
		}
	} while (inShop);
}

bool exists(string name)
{
	//Turns the first letter uppercase
	name[0] = toupper(name[0]);
	//Loops though the list
	for (list<Item>::iterator it = stock.begin(); it != stock.end(); it++) {
		if (it->getName() == name) {
			return true;
		}
	}
	return false;
}

void remove(Player& player, string name)
{
	//Turns the first letter uppercase
	name[0] = toupper(name[0]);
	//Loops though the list
	for (list<Item>::iterator it = stock.begin(); it != stock.end(); it++) {
		//Checks if the ids match
		if (it->getName() == name) {
			//Removes coins from inventory
			player.getInventory().remove(Item("Coins", price));
			//Adds the item to the inventory
			player.getInventory().add(Item(name));
			break;
		}
	}
}

int getPrice(string name)
{
	//Turns the first letter uppercase
	name[0] = toupper(name[0]);
	//Loops though the list
	for (list<Item>::iterator it = stock.begin(); it != stock.end(); it++) {
		if (it->getName() == name) {
			return it->getPrice();
		}
	}
	return 0;
}
