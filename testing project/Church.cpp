#include "pch.h"
#include "Church.h"


Church::Church()
{
}


Church::~Church()
{
}

bool Church::hasTrees()
{
	return false;
}

bool Church::hasWater()
{
	return false;
}

bool Church::canTravel()
{
	return true;
}

list<Npc> Church::getNpcs()
{
	return npcs;
}

list<Item> Church::getGroundItems()
{
	return list<Item>();
}

void Church::removeGrounditem(int itemId)
{
}

void Church::addGrounditem(Item item)
{
}

void Church::removeNpc(int npcId)
{
}

void Church::addNpc(int npcId)
{
	//Adds the npc to the list
	npcs.push_back(Npc(npcId));
}

string Church::onEnterance(Player & player)
{
	if (player.quests[0] < 1) {
		handleOutput("As you enter the church you don't see the priest.\nPeople in the church tell you he was last seen heading to the forest.\n\nDo you want to start the quest 'Find the missing priest'", true);
		string input;
		do {
			//Reads the input
			getline(cin, input);
			//Turns all letters to lower case so the user can type 'Yes' or 'yes'
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			//Checks if input is yes or no
			if (!(input == "yes" || input == "no")) {
				handleOutput("Please fill in yes or no", true);
			}
		} while (!(input == "yes" || input == "no"));
		//Checks if input is yes
		if (input == "yes") {
			//Sets the stage of the quest to 2
			player.quests[0] = 2;
			//Tells the player he started the quest
			handleOutput("You start the quest 'Find the missing priest'.", true);
		}
		//Checks if input is no
		else if (input == "no") {
			//Tells the user he did not start the quest
			handleOutput("You do not start the quest 'Find the missing priest'.", true);
		}
		return "";
	}
	else if (player.quests[0] > 1) {
		return "You enter the church";
	}
	return "You enter the church and get welcomed by the priest";
}
