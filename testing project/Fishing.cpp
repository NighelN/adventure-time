#include "pch.h"
#include "Fishing.h"

bool startFishing(Player& player)
{
	//Checks if the user has fishing rod in his inventory
	if (!player.getInventory().contains("Fishing rod")) {
		handleOutput("You need a fishing rod to start fishing.", true);
		return false;
	}
	//Checks if the user has any fishing bait in his inventory
	if (!player.getInventory().contains("Fishing bait")) {
		handleOutput("You need fishing bait to start fishing.", true);
		return false;
	}
	//Checks if the user is at the right stage of the tutorial
	if (player.tutorialStage < 4) {
		handleOutput("You are not allowed to fish yet.", true);
		return false;
	}
	//Gives the player some feedback
	handleOutput("You start fishing", false);
	//Shows the player hes fishing
	slowText(".....", 500);
	//Checks if your succesfull chopping down the tree
	bool succesfull = rand() % 2 == 0;
	//Builds the message
	string message = succesfull ? "You succesfully caugth a fish." : "The fish got away.";
	//Sends the message
	handleOutput(message, true);
	//Checks if you succesfully caugth a fish
	if (succesfull) {
		//Removes a fishing bait from the inventory
		player.getInventory().remove(Item(5));
		//Adds a raw fish in the inventory
		player.getInventory().add(Item(6));
	}
	return succesfull;
}
