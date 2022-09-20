#include "pch.h"
#include "Dialogue.h"

string getDialogue(Player& player, Npc npc)
{
	string input, output;
	switch (npc.getId()) {
		case 0:
			//Checks for the current tutorial stage
			switch (player.tutorialStage) {
			case 0: //Didnt look around but knew u had to talk to the guide so add to the tutorial stage
				player.tutorialStage++;
			case 1: //When first talking to the guide
				return "\n" + npc.getName() + ": Hello there " + player.playerName + ", My name is Guide am here to explain the basics...\nI can see your wounded so let me tell you about fishing your own food.\nBut first i have to tell you about how you pickup ground items,\nyou can pickup any ground item by using the 'pickup itemname' command.\nGive this a try for the fishing rod and fishing bait.\n";
			case 2: //When you have not yet picked up the fishing rod or bait yet
				return "\n" + npc.getName() + ": I see you have not picked up the fishing rod or bait yet.\nIll refresh your memory, you are able to pickup ground with the 'pickup itemname'.\n";
			case 3: //Has picked up the rod or bait
				return player.getInventory().contains("Fishing rod") ? "\n" + npc.getName() + ": I see you picked up the fishing rod, you still need the fishing bait.\n" : "\n" + npc.getName() + ": I see you picked up fishing bait, you still need the fishing rod.\n";
			case 4: //Has picked up both the rod and bait
				return "\n" + npc.getName() + ": Well done on picking up the fishing rod and bait.\nNow am going to teach you how to catch your own fish to heal yourself with.\nYou can start fishing with the 'start fishing' command, give this a try.\n";
			case 5: //Has caught a fish
				return "\n" + npc.getName() + ": Goodjob, now you need to pickup the axe from the ground.\nAnd chop down a tree using the 'chop tree' command.\nCome back and talk to me once you chopped down a tree.\n";
			case 6: //Has picked up the axe
				return "\n" + npc.getName() + ": I see you picked up the axe, you now need to chop down a tree.\nYou now need to chop down a tree by using the 'chop tree' command.\n";
			case 7: //Has chopped down the tree
				return "\n" + npc.getName() + ": Well done on chopping down the tree, now you need to pickup the tinderbox and light a log with it.\nYou can do that with the 'light log' command, give this a try.\n";
			case 8: //Has picked up the tinderbox
				return "\n" + npc.getName() + ": I see you picked up the tinderbox, now you need to light a log with it.\nYou can do this by using the 'light log' command.\n";
			case 9: //Has made a fire
				return "\n" + npc.getName() + ": Well done, now am going to teach you how you can cook your own fish.\nYou can cook fish with the 'cook fish' command, there is a small chance that you burn the fish, give this a try.\n";
			case 10: //Has cooked his fish
				return "\n" + npc.getName() + ": Well done, you are now able to heal your wounds by eating the cooked fish.\nYou are able to do that with the 'eat fish' command, give this a try.\n";
			case 11: //Has eaten the cooked fish, tell about combat
				player.tutorialStage++;
				return "\n" + npc.getName() + ": Well done, am now going to tell you how you can attack monsters around the game.\nYou can use the 'attack npcname' command, give this a try on the rat over there.\n";
			case 12: //Has not defeated the rat yet
				return "\n" + npc.getName() + ": I see you have not yet defeated the rat, remember you can do this with the 'attack npcname' commands.";
			case 13: //Finished killing the rat
				player.getInventory().add(Item(7));
				player.tutorialStage++;
				return "\n" + npc.getName() + ": Well done, here you have a cooked fish for the damage you might have taken.\nNow that you finished the tutorial you are able to explore the island.\nYou can do this by using the 'north'/'east'/'south' or 'west' command.\n";
			case 14:
				return "\n" + npc.getName() + ": Welcome back " + player.playerName + ", remember you are able to explore the island with the following commands: 'north'/'east'/'south' or 'west'.\n";
			}
			break;
		case 2:
			switch (player.quests[0]) {
				case 0:
					//Checks if the user wants the help the priest
					handleOutput("\nAs you approach the priest you see he is hurt and unconscious.\n\nDo you wish to help the priest.", true);
					do {
						//Reads the input
						getline(cin, input);
						//Turns all letters to lower case so the user can type 'Yes' or 'yes'
						transform(input.begin(), input.end(), input.begin(), ::tolower);
						//Checks if the input is yes or no
						if (!(input == "yes" || input == "no")) {
							handleOutput("Please fill in Yes or No.", true);
						}
					} while (!(input == "yes" || input == "no"));
					//Checks if input is yes
					if (input == "yes") {
						//Tells the user he wakes up the priest
						handleOutput("You try to wake up the priest, after a while he wakes up.\nAnd he says the following", true);
						//Sets stage of quest to 0
						player.quests[0] = 3;
						//Fills the output
						output = npc.getName() + ": Could you please go to Sharnwick and pick me up some medicine from the store.";
					}
					//Checks if input is no
					else if (input == "no")
						//Fills the output
						output = "Maybe i can help him at another time.";
					break;
				case 2:
					//Tells the user he approaches the priest
					handleOutput("\nAs you approach the priest, you see he is hurt and unconscious.\nYou try to wake up the priest, after a while he wakes up.\nAnd he says the following.", true);
					//Sets stage of quest to 0
					player.quests[0] = 3;
					//Fills the output
					output = npc.getName() + ": Could you please go to Sharnwick and pick me up some medicine from the store.";
					break;
				case 3:
					//Fills the output
					output = npc.getName() + ": Could you please go to Sharnwick and pick me up some medicine from the store.";
					break;
				case 4:
					//Checks if the user has the medicine
					if (player.getInventory().contains("Medicine")) {
						//Removes the medicine from the medicine from the players inventory.
						player.getInventory().remove(Item("Medicine"));
						//Adds 100 coins to the inventory
						player.getInventory().add(Item("Coins", 100));
						//Fills the output
						output = npc.getName() + ": Thank you very much, here have this reward for helping me.\n\nFind the missing priest Quest completed:\n\nYou receive 100 coins from the priest";
						//Sets the quest stage to 5
						player.quests[0] = 5;
					}
					//If the player somehow lost the medicine
					else {
						//Fills the input
						output = npc.getName() + ": Please bring me the medicine.";
					}
					break;
				case 1:
					//Fills the output
					output = npc.getName() + ": Once again thanks for helping me, i will pray for you on this journey.";
					break;
			}
			return output;
		case 5:
		case 6:
			return "\nIt's a lovely day isn't it.\nYou should visit the church on the east.\n";
		case 7:
		case 8:
			return handleStore(player, npc);
		case 9:

			//Checks if the user has started the 'Broken shield' quest
			if (player.quests[1] == 2 && player.getInventory().contains("Broken shield")) {
				//Gives the user feedback about the output
				handleOutput(npc.getName() + ": Woooooow, you found the long lost shield from our kingdom.\nLet me give you a reward for bringing it back.", true);
				//Removes the shield from the inventory
				player.getInventory().remove(Item("Broken shield"));
				//Gives the user 100 coins
				player.getInventory().add(Item("Coins", 100));
				return "";
			}

			return handleStore(player, npc);

	}

	return "";
}

string handleStore(Player& player, Npc npc) {
	string input, output;
	handleOutput("\n" + npc.getName() + ": Hello there " + player.playerName + ", What are you looking for?\n[Open store] or [Leave]", true);
	do {
		//Reads the input
		getline(cin, input);
		//Turns all letters to lower case so the user can type 'Yes' or 'yes'
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		//Checks if the input is yes or no
		if (!(input == "open store" || input == "leave")) {
			handleOutput("Please fill in open store or leave.", true);
		}
	} while (!(input == "open store" || input == "leave"));
	//Checks if the input is 'open store'
	if (input == "open store") {
		//Opens up the store
		openShop(player, npc.getId());
	}
	//Checks if the input is leave
	else if (input == "leave") {
		//Fills the output
		output = "You leave the clerk alone.";
	}
	return output;
}
