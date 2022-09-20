#include "pch.h"
#include "Firemaking.h"

bool lightLog(Player& player)
{
	//Checks if the player has a tinderbox in his inventory
	if (!player.getInventory().contains("Tinderbox")) {
		handleOutput("You need a tinderbox to light a fire.", true);
		return false;
	}
	//Checks if the player has a log in his inventory
	if (!player.getInventory().contains("Log")) {
		handleOutput("You need a log to light a fire.", true);
		return false;
	}
	//Checks if the user is at the right stage of the tutorial
	if (player.tutorialStage < 8) {
		handleOutput("You are not allowed to light a log yet.", true);
		return false;
	}
	//Gives the player some feedback
	handleOutput("You start lighting the log", false);
	//Shows the player hes lighting the log
	slowText(".....", 500);
	//Checks if your succesfull chopping down the tree
	bool succesfull = rand() % 2 == 0;
	//Builds the message
	string message = succesfull ? "You manage to light the log on fire." : "You failed to light the log.";
	//Sends the message
	handleOutput(message, true);
	//If sucessfully light the log
	if (succesfull) {
		//Removes the item
		player.getInventory().remove(Item(2));
		//Sets the player having a fire to true
		player.hasFire = true;
	}
	return succesfull;
}
