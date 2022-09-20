#include "pch.h"
#include "Combat.h"

bool handleCombat(Maps * map, Player& player, Npc & npc)
{
	//Checks if the npc is 'Npc does not exist.'
	if (npc.getName() == "Npc does not exist.") {
		handleOutput("You are not able to find the npc your trying to attack.", true);
		return false;
	}
	//Checks if the npc is attackable
	if (!npc.isAttackable()) {
		handleOutput("You are not allowed to attack the " + npc.getName() + ".", true);
		return false;
	}
	//Tell the player how the combat works
	if (player.tutorialStage == 12) {
		handleOutput("You are able to attack monsters with the 'attack with weaponname' command.\nOr you can run away with the 'run away' command, you are also able to heal yourself with the 'eat fish' command.", true);
	}
	//Makes it so the player is in combat
	player.inCombat = true;
	//Keep looping while its in combat
	do {
		//Tells the user his own hitpoints and the enemys health
		handleOutput("Your health: " + to_string(player.getHealth()) + "\nEnemy health: " + to_string(npc.getHealth()) + "\n\nWhat would you like to do:", true);
		bool finished_turn = false;
		while (!finished_turn) {
			string input;
			//Reads the users input
			getline(cin, input);
			//Transforms all letters to lowercase
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			//Checks if the user wants to attack with something
			if (input.rfind("attack with", 0) == 0) {
				string beginCommand = "attack with", weapon = input.substr(beginCommand.length() + 1);
				//Converts the first letter of the weapon to uppercase
				weapon[0] = toupper(weapon[0]);
				//Checks if the weapon is either your 'fist'/'feet' or a weapon
				if (weapon == "Fist" || weapon == "Feet" || player.getInventory().contains(weapon)) {
					//Picks a random number between 0 and the max damage the user can do
					int damage = rand() % (player.getDamage(weapon) + 1);
					//Tells the user how much damage he did
					handleOutput("You deal " + to_string(damage) + " damage to the " + npc.getName() + ".", true);
					//Removes the damage from the npcs health
					npc.setHealth(npc.getHealth() - damage);
					//Checks if the npc has no health left over
					if (npc.getHealth() <= 0) {
						//Finishes the whole combat
						player.inCombat = false;
						//Tells the user he defeated the npc
						handleOutput("You have defeated the " + npc.getName() + ".", true);
						//Removes the npc from the map
						map->removeNpc(npc.getId());
						//If monster is ogre drop the broken shield
						if (npc.getId() == 13) {
							//Adds the broken shield to the ground items
							map->addGrounditem(Item("Broken shield"));
							//Gives the player some feedback
							handleOutput("As the ogre dies it drops a broken shield onto the floor.", true);
						}
						//Checks if the monster you killed is the dragon
						else if (npc.getId() == 14) {
							//Adds the sword of immense power to the ground
							map->addGrounditem(Item("Sword of immense power"));
							//Gives the user feedback
							handleOutput("As the dragon dies it drops the Sword of immense power onto the floor.", true);
						}
					}
					//Finishes your turn and this while loop
					finished_turn = true;

				}
				//If the user isnt attack with a 'fist'/'feet' or a weapon he owns
				else {
					handleOutput("You do not have the " + weapon + " to attack with.", true);
				}
			}
			//Checks if the user is eating food
			else if (input.rfind("eat", 0) == 0) {
				string beginCommand = "eat", action = input.substr(beginCommand.length() + 1);
				//Checks if you are trying to eat the fish
				if (action == "fish") {
					//Checks if the user has a fish in his inventory
					if (!player.getInventory().contains("Cooked fish")) {
						handleOutput("You do not have a cooked fish to eat.", true);
						return false;
					}
					//Increases the players health by 5
					player.setHealth(player.getHealth() + 5);
					//Sends the player a message
					handleOutput("You eat the cooked fish.", true);
				}
				else {
					handleOutput("You are not able to eat the " + action + ".", true);
				}
			}
			else if (input == "run away") {
				//Finishes your turn and this while loop
				finished_turn = true;
				//Finishes the whole combat
				player.inCombat = false;
				//Tells the user he ran away from the combat
				handleOutput("You run away from the " + npc.getName() + ".", true);
			}
			else {
				handleOutput("Could not find your command, please try again.", true);
			}
		}
		//If you are not in combat anymore (aka run away) it breaks out of the loop
		if (!player.inCombat) {
			break;
		}
		//Gives a little delay between your and the npc there attack
		Sleep(1000);
		//Grabs random damage for the npc
		int damage = rand() % (npc.getDamage() + 1);
		//Tells the user how much damage he took
		handleOutput("You took " + to_string(damage) + " damage from the " + npc.getName() + ".", true);
		//Removes the damage from the players health
		player.setHealth(player.getHealth() - damage);
		//Checks if the player died or not
		if (player.getHealth() <= 0) {
			//Stops the loop because the player died
			player.inCombat = false;
		}
		//Gives a little delay between the npc and yours attack
		Sleep(1000);
	} while (player.inCombat);

	//Handle the death of the player
	if (player.getHealth() <= 0) {
		//Tells the user he dies
		handleOutput("You have died.", true);
		//Pauses the game
		system("pause");
		//Stops the game
		exit(0);
		return false;
	}

	//Tells the user he is out of combat
	handleOutput("You are now out of combat.", true);
	return true;
}
