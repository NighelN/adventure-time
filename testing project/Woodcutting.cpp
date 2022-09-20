#include "pch.h"
#include "Woodcutting.h"

bool startChopping(Player& player)
{
	//Checks if the user has an axe in his inventory
	if (!player.getInventory().contains("Axe")) {
		handleOutput("You do not have an axe to chop down the tree.", true);
		return false;
	}
	//Checks if the player has any free slots
	if (player.getInventory().freeSlots() <= 0) {
		handleOutput("You do not have any room in your inventory.", true);
		return false;
	}
	//Checks if the user is at the right stage of the tutorial
	if (player.tutorialStage < 6) {
		handleOutput("You are not allowed to chop down trees yet.", true);
		return false;
	}
	//Gives the player some feedback
	handleOutput("You start chopping the tree", false);
	//Shows the player hes woodcutting
	slowText(".....", 500);
	//Checks if your succesfull chopping down the tree
	bool succesfull = rand() % 2 == 0;
	//Builds the message
	string message = succesfull ? "You manage to chop down the tree." : "You failed to chop down the tree";
	//Sends the message
	handleOutput(message, true);
	//If sucessfull add an log
	if (succesfull) {
		player.getInventory().add(Item(2));
	}
	return succesfull;
}
