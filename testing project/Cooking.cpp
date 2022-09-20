#include "pch.h"
#include "Cooking.h"

bool startCooking(Player& player)
{
	//Checks if the player has a tinderbox in his inventory
	if (!player.getInventory().contains("Raw fish")) {
		handleOutput("You don't have a raw fish to cook.", true);
		return false;
	}
	//Checks if the player has a fire
	if (!player.hasFire) {
		handleOutput("You don't have a fire to cook a fish on.", true);
		return false;
	}
	//Checks if the user is at the right stage of the tutorial
	if (player.tutorialStage < 9) {
		handleOutput("You are not allowed to cook a fish yet.", true);
		return false;
	}
	//Gives the player some feed back
	handleOutput("You start cooking the fish", false);
	//Shows the player he is cooking
	slowText(".....", 500);
	//Checks if your succesfull chopping down the tree
	bool succesfull = rand() % 2 == 0;
	//Builds the message
	string message = succesfull || player.tutorialStage == 9 ? "You manage to cook the fish." : "You accidently burned the fish.";
	//Sends the message
	handleOutput(message, true);
	//Remove the raw fish
	player.getInventory().remove(Item(6));
	//If sucessfull add cooked or burned fish
	if (succesfull || player.tutorialStage == 9) {
		//Add cooked fish
		player.getInventory().add(Item(7));
	}
	else {
		//Add burned fish
		player.getInventory().add(Item(8));
	}
	return succesfull;
}