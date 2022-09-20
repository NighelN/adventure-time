#include "pch.h"
#include "GameManager.h"

Player player;
bool gameRunning = true;
int textSpeed = 0;

Maps * maps[12][12] = {
	{new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty()},
	{new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Dungeon_Two(), new Empty()},
	{new Empty(), new Empty(), new Tutorial(), new Empty(), new Empty(), new Empty(), new FishingDock(), new Empty(), new Empty(), new Empty(), new Path(), new Empty()},
	{new Empty(), new Empty(), new Mensfield(), new Church(), new Empty(), new Empty(), new FishingStore(), new Empty(), new Empty(), new Empty(), new Path(), new Empty()},
	{new Empty(), new Empty(), new Forest(), new Empty(), new Shed(), new Empty(), new FishingDock(), new Empty(), new Empty(), new Empty(), new Path(), new Empty()},
	{new Empty(), new Empty(), new Forest(), new Forest(), new Forest(), new Forest(), new FisherKingdom(), new Path(), new Path(), new Path(), new Path(), new Empty()},
	{new Empty(), new Empty(), new Path(), new Empty(), new Empty(), new Empty(), new Path(), new Empty(), new Path(), new Empty(), new Path(), new Empty()},
	{new Empty(), new Path(), new Path(), new Empty(), new Dungeon_One(), new Empty(), new Path(), new Empty(), new Forest(), new Empty(), new Path(), new Empty()},
	{new Empty(), new Path(), new Empty(), new Empty(), new Path(), new Empty(), new Path(), new Empty(), new Empty(), new MedicineStore(), new Sharnwick(), new Empty()},
	{new Empty(), new Ironforge(), new Path(), new Path(), new Path(), new Empty(), new Path(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty()},
	{new Empty(), new WeaponStore(), new Empty(), new Empty(), new Path(), new Path(), new Path(), new Path(), new Path(), new Path(), new Dungeon(), new Empty()},
	{new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty(), new Empty()}
};

string main_menu[27] = {
" ____________________________________________________________________________________________\n",
"|                                                                                            |\n",
"|    _____       .___                    __                           __  .__                |\n",
"|   /  _  \\    __| _/__  __ ____   _____/  |_ __ _________   ____   _/  |_|__| _____   ____  |\n",
"|  /  /_\\  \\  / __ |\\  \\/ // __ \\ /    \\   __\\  |  \\_  __ \\_/ __ \\  \\   __\\  |/     \\_/ __ \\ |\n",
"| /    |    \\/ /_/ | \\   /\\  ___/|   |  \\  | |  |  /|  | \\/\\  ___/   |  | |  |  Y Y  \\  ___/ |\n",
"| \\____|__  /\\____ |  \\_/  \\___  >___|  /__| |____/ |__|    \\___  >  |__| |__|__|_|  /\\___ > |\n",
"|         \\/      \\/           \\/     \\/                        \\/                 \\/     \\/ |\n",
"|                                                                                            |\n",
"|                                                                   (o)                      |\n",
"|  ____________________                                             xxx                      |\n",
"| |     Main Menu      |                                            xxx                      |\n",
"| |____________________|                                        ____xxx____                  |\n",
"| |                    |                                        `---------'                  |\n",
"| |       Start        |                                           |   |                     |\n",
"| |                    |                                           |   |                     |\n",
"| |                    |                                           |   |                     |\n",
"| |                    |                                           |   |                     |\n",
"| |        Quit        |                                           |   |                     |\n",
"| |                    |                                     ______|___|_____                |\n",
"| |                    |                                  __/                \\               |\n",
"| |  Made by Mobjunk   |                                 /         \\          |              |\n",
"| |     Aka Nighel     |                                |    _\\\\_   |         |\\             |\n",
"| |____________________|                                |     \\\\    |         | |      ___   |\n",
"|                                                __    /     __     |         | |    _/   \\  |\n",
"|                                               /__\\  |_____/__\\____|_________|__\\  /__\\___\\ |\n",
"|____________________________________________________________________________________________|\n",
};

void menu()
{
	//Clears the screen
	system("CLS");
	//Loops though the main menu
	for (int index = 0; index < sizeof(main_menu) / sizeof(*main_menu); index++)
		//Display the main menu
		handleOutput(main_menu[index], false);
	//Creates an instance of the coice
	string input;
	//Checks if your input was correct
	bool correctInput = false;
	//Keep looping untill your choice is between start and quit
	do {
		//Reads the users input
		getline(cin, input);
		//Clears cin to stop control z
		cin.clear();
		//Transforms all letters to lowercase
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		//If the choice is not start or quit
		if (input == "start" || input == "quit") {
			//Sets the correct input to true
			correctInput = true;
		}
		else {
			//Give the user input about there mistake
			handleOutput("Please fill in start or quit.", true);
		}
	} while (!correctInput);
	//Checks if the player picked start
	if (input == "start") {
		start();
	}
	//Checks if the player picked quit
	else if (input == "quit") {
		exit(0);
	}
}

void start()
{
	//Clears the players inventory incase of a reset
	player.clear();
	//Clears the screen
	system("CLS");
	//Sets the first map piece
	maps[2][2] = new Tutorial();
	//Sets the main town
	maps[3][2] = new Mensfield();
	//Asks the player there name
	slowText("Please enter your player's name:", textSpeed);
	//Reads the name the player put in
	getline(cin, player.playerName);
	//Clears cin to stop control z
	cin.clear();
	//Aks the player there gender
	slowText("Please enter your gender[Male/Female]:", textSpeed);
	//Creates an temp string for gender
	string gender;
	do {
		//Reads the gender the user filled in
		getline(cin, gender);
		//Clears cin to stop control z
		cin.clear();
		//Transforms all letters to lowercase
		transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
		//Checks if the input isnt male or female
		if (!(gender == "male" || gender == "female")) {
			//Sends the player some feedback
			handleOutput("Please fill in either Male or Female:", true);
		}
	} while (!(gender == "male" || gender == "female"));
	//Fills the players gender
	gender = gender;
	//Asks the user if he wants to skip the tutorial
	slowText("Do you wish to skip the tutorial[Yes/No]:", textSpeed);
	string skip_tutorial;
	do {
		//Reads the tutorial the user filled in
		getline(cin, skip_tutorial);
		//Clears cin to stop control z
		cin.clear();
		//Transforms all letters to lowercase
		transform(skip_tutorial.begin(), skip_tutorial.end(), skip_tutorial.begin(), ::tolower);
		//Checks if the input isnt male or female
		if (!(skip_tutorial == "yes" || skip_tutorial == "no")) {
			//Sends the player some feedback
			handleOutput("Please fill in either Yes or No:", true);
		}
		else {
			if (skip_tutorial == "yes") {
				//Sets the tutorial stage to 14
				player.tutorialStage = 14;
				//Places the player on the spawn location
				player.move(2, 3);
			}
		}

	} while (!(skip_tutorial == "yes" || skip_tutorial == "no"));
	//Clears the screen
	system("CLS");
	//Sends the welcome message
	slowText(getMap()->onEnterance(player), textSpeed);
	//Runs the game loop
	run();
}

void run()
{
	do {
		//The command the user types
		string command;
		//Reads the command
		getline(cin, command);
		//Clears cin to stop control z
		cin.clear();
		//Handles the command the user types
		handleCommands(command);
	} while (gameRunning);
}

void handleCommands(string command)
{
	//Turns all letters to lower case so the user can type 'Help' or 'help'
	transform(command.begin(), command.end(), command.begin(), ::tolower);
	//Checks if the user typed the command help
	if (command == "help") {
		string help;
		switch (player.tutorialStage) {
		case 0: //Needs to look around
			help = "Maybe i should use the 'look around' command.";
			break;
		case 1: //Needs to talk to
			help = "Maybe i should use the 'talk to guide' command.";
			break;
		case 2://Needs to pickup the fishing rod and bait
		case 3:
			help = "Maybe i should use the 'pickup fishing rod/bait' command.";
			break;
		case 4: //Has to start fishing
			help = "Maybe i should use my fishing rod and bait with the 'start fishing' command.";
			break;
		case 5: //Has to pickup an axe
			help = "Maybe i should pickup the axe with the 'pickup axe' command.";
			break;
		case 6: //Needs to chop down a tree
			help = "Maybe i should chop a tree with the 'chop tree' command.";
			break;
		case 7: //Needs to pickup a tinderbox
			help = "Maybe i should pickup the tinderbox with the 'pickup tinderbox' command.";
			break;
		case 8: //Needs to light a log
			help = "Maybe i should light the log with the tinerbox using the 'light log' command.";
			break;
		case 9: //Needs to cook a fish
			help = "Maybe i should cook a fish with the 'cook fish' command.";
			break;
		case 10: //Eat the cooked fish
			help = "Maybe i should eat the cooked fish with the 'eat fish' command.";
			break;
		case 12: //Kill the rat
			help = "Maybe i should attack the rat with the 'attack rat' command.";
			break;
		case 13: //Walk south
			help = "Maybe i should move to the main town using the 'south' command.";
			break;
		case 14: //Nothing left to say
			help = "No more help required, use the command 'commands' to see all possible commands";
			break;
		}
		//Sends slow text to the console
		slowText(help, textSpeed);
	}
	//Checks if the user typed the command commands
	else if (command == "commands") {
		//All commands
		string commands[16] = { "help", "inventory" , "look around" , "north" , "east" , "south" , "west" , "chop" , "light" , "start", "cook", "eat", "pickup", "talk to", "attack", "quests" };
		//Current outcome
		string outcome;
		//Size of the array
		int size = sizeof(commands) / sizeof(*commands);
		//Loops though the possible commands
		for (int index = 0; index < size; index++) {
			outcome += commands[index];
			//if its not the end add a ,
			if (index != size - 1)
				outcome += ", ";
		}
		//Displays all commands
		handleOutput(outcome, true);
	}
	//Checks if the user typed the quests command
	else if (command == "quests") {
		//All quests
		string quests[2] = { "Find the missing priest", "Retreive the broken shield" };
		//Size of the quests
		int size = sizeof(quests) / sizeof(*quests);
		for (int index = 0; index < size; index++) {
			handleOutput(quests[index] + " - " + (player.quests[index] > 1 ? "In progress" : player.quests[index] == 1 ? "Completed" : "Not started"), true);
		}
	}
	//Checks if the user typed the command inventory
	else if (command == "inventory" || command == "inv") {
		//Prints the inventory
		player.getInventory().printInventory();
	}
	//Prints some data about the map
	else if (command == "map" || command == "look around") {
		//If stage of the tutorial is 0 add to it
		if (player.tutorialStage == 0) {
			//Increases the tutorial stage
			player.tutorialStage++;
		}
		//Displays some text slowly
		slowText("\nAs you look around you see the following:\n", textSpeed);
		//Displays information about the trees in your area
		slowText("There are" + (getMap()->hasTrees() == 1 ? string("") : string(" no")) + " trees around you", textSpeed);
		//Displays information about the water in your area
		slowText("There is" + (getMap()->hasWater() == 1 ? string("") : string(" no")) + " water around you", textSpeed);
		//Display all npcs in this map
		string npcs = "You see the following npcs: ";
		//Current item index
		int index = 0;
		for (Npc npc : getMap()->getNpcs()) {
			npcs += npc.getName();
			//If its not the end of the loop add a ,
			if (index != getMap()->getNpcs().size() - 1)
				npcs += ", ";
			index++;
		}
		//Prints the npcs slowly to the console
		slowText(npcs, textSpeed);
		//Display all ground items in this map
		string groundItems = "You see the following items on the ground: ";
		//Current item index
		index = 0;
		for (Item item : getMap()->getGroundItems()) {
			groundItems += item.getName();
			//If its not the end of the loop add a ,
			if (index != getMap()->getGroundItems().size() - 1)
				groundItems += ", ";
			index++;
		}
		//Prints the ground items slowly to console
		slowText(groundItems, textSpeed);
		//Checks if the current stage of the tuorial is 1
		if (player.tutorialStage == 1) {
			slowText("\nMaybe i should talk to the guide over there.\n", textSpeed);
		}
	}
	//Resets the game
	else if (command == "reset") {
		//Resets the game
		menu();
	}
	//Makes the user travel in a direction
	else if (command == "north" || command == "east" || command == "south" || command == "west") {
		//Checks if the user is allowed to travel yet.
		if (player.tutorialStage < 14) {
			handleOutput("You are not allowed to explore the island yet.", true);
			return;
		}
		//Handles the traveling
		travel(command);
	}
	//Checks if the user used the chop command
	else if (command.rfind("chop", 0) == 0) {
		//Checks if there is something to chop
		if (command == "chop") {
			handleOutput("You need to specify something to chop.", true);
			return;
		}
		string beginCommand = "chop", action = command.substr(beginCommand.length() + 1);
		//Checks if the command contains tree
		if (action == "tree") {
			//Checks if there are any trees in the current map
			if (getMap()->hasTrees()) {
				//Start chopping a tree
				if (startChopping(player)) {
					//If tutorial stage is 6 (chopping trees) increase it
					if (player.tutorialStage == 6) {
						//Increase tutorial stage
						player.tutorialStage++;
						//Gives dialogue
						slowText(getDialogue(player, getNpc("Guide")), textSpeed);
					}
				}
			}
			else {
				//Tells the player there are no trees to chop
				handleOutput("There are no trees around to chop down.", true);
			}
		}
		else {
			handleOutput("You are not allowed to chop down the " + action + ".", true);
		}
	}
	//Checks if the user is trying to light a log
	else if (command.rfind("light", 0) == 0) {
		//Checks if there is nothing to light
		if (command == "light") {
			handleOutput("You need to specify something to light.", true);
			return;
		}
		string beginCommand = "light", action = command.substr(beginCommand.length() + 1);
		//Checks if the command contains log
		if (action == "log") {
			//Attempt to light a log
			if (lightLog(player)) {
				//If tutorial stage is 8 (lighting logs) increase it
				if (player.tutorialStage == 8) {
					//Increase tutorial stage
					player.tutorialStage++;
					//Gives dialogue
					slowText(getDialogue(player, getNpc("Guide")), textSpeed);
				}
			}
		}
		//If your trying to light something else on fire
		else {
			handleOutput("You are not allowed to light the " + action + " on fire.", true);
		}
	}
	//Checks if the user is trying to use the start command
	else if (command.rfind("start", 0) == 0) {
		//Checks if there is nothing to start
		if (command == "start") {
			handleOutput("You need to specify something to start.", true);
			return;
		}
		string beginCommand = "start", action = command.substr(beginCommand.length() + 1);
		//Checks if the action is fishing
		if (action == "fishing") {
			//Checks if there is water in this area
			if (getMap()->hasWater()) {
				//Starts fishing
				if (startFishing(player)) {
					//Checks if the tutorial stage is (start fishing)
					if (player.tutorialStage == 4) {
						//Increase the stage
						player.tutorialStage++;
						//Gives dialogue
						slowText(getDialogue(player, getNpc("Guide")), textSpeed);
					}
				}
			}
			//There is no water in this area
			else {
				handleOutput("There is no water to fish in.", true);
			}
		}
		//There is nothing with the given 'start'
		else {
			handleOutput("You are not able to start " + action + ".", true);
		}
	}
	//Checks if the user is trying to use the cook command
	else if (command.rfind("cook", 0) == 0) {
		//Checks if there is nothing to cook
		if (command == "cook") {
			handleOutput("You need to specify something to eat.", true);
			return;
		}
		string beginCommand = "cook", action = command.substr(beginCommand.length() + 1);
		//Checks if your trying to cook a fish
		if (action == "fish") {
			//Starts cooking
			if (startCooking(player)) {
				//If tutorial stage is 9 (cook a fish) increase it
				if (player.tutorialStage == 9) {
					//Increase tutorial stage
					player.tutorialStage++;
					//Gives dialogue
					slowText(getDialogue(player, getNpc("Guide")), textSpeed);
				}
			}
		}
		else {
			handleOutput("You are not allowed to cook the " + action + ".", true);
		}
	}
	//Prints the position of the player
	else if (command == "pos") {
		cout << "X: " << player.getX() << ", Y: " << player.getY() << endl << endl;
	}
	//Checks if the user is trying to eat something
	else if (command.rfind("eat", 0) == 0) {
		//Checks if there is nothing to eat
		if (command == "eat") {
			handleOutput("You need to specify something to eat.", true);
			return;
		}
		string beginCommand = "eat", action = command.substr(beginCommand.length() + 1);
		//Checks if you are trying to eat the fish
		if (action == "fish") {
			//Checks if your allowed to eat a fish yet
			if (player.tutorialStage < 10) {
				handleOutput("You are not allowed to eat fish yet.", true);
				return;
			}
			//Checks if the user has a fish in his inventory
			if (!player.getInventory().contains("Cooked fish")) {
				handleOutput("You do not have a cooked fish to eat.", true);
				return;
			}
			//Increases the players health by 5
			player.setHealth(player.getHealth() + 5);
			//Sends the player a message
			handleOutput("You eat the cooked fish.", true);
			//If your at the stage (eating a fish) increase the tutorial stage
			if (player.tutorialStage == 10) {
				handleOutput("You succesfully heal all your wounds.", true);
				player.tutorialStage++;
				//Gives dialogue
				slowText(getDialogue(player, getNpc("Guide")), textSpeed);
			}
		}
		else {
			handleOutput("You are not able to eat the " + action + ".", true);
		}
	}
	//Checks if the user is trying to pickup an ground item
	else if (command.rfind("pickup", 0) == 0 || command.rfind("take", 0) == 0 || command.rfind("grab", 0) == 0) {
		//Checks if there is nothing to pickup
		if (command == "pickup" || command == "take" || command == "grab") {
			handleOutput("You need to specify a item to pickup.", true);
			return;
		}
		string beginCommand = command.rfind("pickup", 0) == 0 ? "pickup" : command.rfind("take", 0) == 0 ? "take" : "grab", pickup = command.substr(beginCommand.length() + 1);
		//Checks if you found the item
		bool foundItem = false;
		//Loops though all ground items in this area
		for (Item item : getMap()->getGroundItems()) {
			//Grabs the item name
			string itemName = item.getName();
			//Transforms all letters to lowercase
			transform(itemName.begin(), itemName.end(), itemName.begin(), ::tolower);
			//If the names dont match skip
			if (itemName != pickup) continue;
			//Checks if the player is already allowed to use the pickup command.
			if (player.tutorialStage < 2) {
				handleOutput("You do not know yet what you have to do with this item, so you put it back.", true);
				//Sets it to true
				foundItem = true;
				break;
			}
			//Checks if your picking up any other item expect the axe in stage 2 of the tutorial
			if (player.tutorialStage == 2 && (pickup != "fishing rod" && pickup != "fishing bait")) {
				handleOutput("You are supposed to pickup the fishing rod and bait.", true);
				//Sets it to true
				foundItem = true;
				break;
			}
			//Adds the item to the inventory
			player.getInventory().add(item);
			//Gives the user feedback
			handleOutput("You have picked up the " + itemName + " from the ground.", true);
			//Removes the ground item
			getMap()->removeGrounditem(item.getId());
			//If your tutorial stage is 2 (picking up item) increase it
			if (((player.tutorialStage >= 2 && player.tutorialStage <= 3) && (pickup == "fishing rod" || pickup == "fishing bait")) || (player.tutorialStage == 5 && pickup == "axe") || (player.tutorialStage == 7 && pickup == "tinderbox")) {
				//Checks if its your first time picking up a ground item, it will tell you about your inventory
				if (player.tutorialStage == 2) {
					handleOutput("You are able to see your items with the 'inventory' command.", true);
				}
				player.tutorialStage++;
				//Specific tutorial stage
				if (player.tutorialStage == 4 || player.tutorialStage == 5 || player.tutorialStage == 7) {
					//Gives dialogue
					slowText(getDialogue(player, getNpc("Guide")), textSpeed);
				}
			}
			//Checks if the user is picking up the broken shield and has not started the quest yet
			else if (pickup == "broken shield" && player.quests[1] == 0) {
				//Sets the quest stage to 2
				player.quests[1] = 2;
			}
			//Checks if the user is picking up the Sword of immense power
			else if (pickup == "Sword of immense power") {
				//Tells the user he won the game
				handleOutput("You have defeated the game.", true);
				//Sets gameRunning to false
				gameRunning = false;
				//Pauses the game
				system("pause");
				//Stops the game
				exit(0);
			}
			//Sets it to true
			foundItem = true;
			break;
		}
		//Has not found the item so give feedback its not found
		if (!foundItem) {
			handleOutput("The item " + pickup + " is not on the ground.", true);
		}
	}
	//Checks if the user is trying to speak to an npc
	else if (command.rfind("talk to", 0) == 0 || command.rfind("talk", 0) == 0) {
		//Checks if there is no npc to talk to
		if (command == "talk to" || command == "talk") {
			handleOutput("You need to specify a npc to talk to.", true);
			return;
		}
		string beginCommand = command.rfind("talk to", 0) == 0 ? "talk to" : "talk", talk_to = command.substr(beginCommand.length() + 1);
		//Gives dialogue
		slowText(getDialogue(player, getNpc(talk_to)), textSpeed);
		//Checks if your in the first stage
		if (player.tutorialStage == 1) {
			//Increase tutorial stage
			player.tutorialStage++;
		}
		//Checks the ending of the quest
		else if (player.quests[0] == 5) {
			//Removes the priest from the shed
			getMap()->removeNpc(2);
			//Adds the priest back to the church
			getMap(3, 3)->addNpc(2);
			//Sets the quest stage to 1
			player.quests[0] = 1;
		}
	}
	//Checks if the user is trying to attack an npc
	else if (command.rfind("attack", 0) == 0 || command.rfind("kill", 0) == 0) {
		//Checks if there is no npc to talk to
		if (command == "attack" || command == "kill") {
			handleOutput("You need to specify a npc to attack.", true);
			return;
		}
		string beginCommand = command.rfind("attack", 0) == 0 ? "attack" : "kill", attack = command.substr(beginCommand.length() + 1);
		//Checks if the player is allowed to attack npcs yet
		if (player.tutorialStage < 12) {
			handleOutput("You are not allowed to attack npcs yet.", true);
			return;
		}
		//Grabs the npc
		Npc npc = getNpc(attack);
		//Starts combat
		if (handleCombat(getMap(), player, npc)) {
			//Checks if the player is in stage 12 (attack rat)
			if (player.tutorialStage == 12) {
				//Increase tutorial stage
				player.tutorialStage++;
				//Gives dialogue
				slowText(getDialogue(player, getNpc("Guide")), textSpeed);
			}
		}
	}
	//If the user typed anything that the program does not know
	else {
		handleOutput("The command " + command + " does not exist.", true);
	}
}

void travel(string direction)
{
	//Gets the x and y position of the player
	int x = player.getX(), y = player.getY();
	//Checks if the direction the player picked is north
	if (direction == "north") {
		y--;
	}
	//Checks if the direction the player picked is east
	else if (direction == "east") {
		x++;
	}
	//Checks if the direction the player picked is south
	else if (direction == "south") {
		y++;
	}
	//Checks if the direction the player picked is west
	else if (direction == "west") {
		x--;
	}
	//Checks if the map is null
	if (getMap(x, y) == NULL) {
		return;
	}
	//Checks if the map gives a nullpointer
	if (getMap(x, y) == nullptr) {
		return;
	}
	//Checks if the new x or y is outside the array
	if (x < 1 || x > 11 || y < 1 || y > 11) {
		handleOutput("You cannot travel there.", true);
		return;
	}
	//Checks if your allowed to travel to this place
	bool travel = getMap(x, y)->canTravel();
	//If your not allowed to travel give this message
	if (!travel) {
		handleOutput("You cannot travel there.", true);
	}
	else {
		//Checks if your traveling to a dungeon
		if ((x == 4 && y == 7) || (x == 10 && y == 1) || (x == 10 && y == 10)) {
			handleOutput("You are about to enter a dungeon, are you sure you want to enter:\n[Yes/No]", true);
			string input;
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
			//Checks if input is no
			if (input == "no") {
				//Tells the user he did not enter the dungeon
				handleOutput("You do not enter the dungeon.", true);
				return;
			}
		}
		//Gives the user feedback he traveled
		handleOutput("You travel "+direction+".", true);
		//Moves the player to the new map
		player.move(x, y);
		//Tells the player the welcome message of the map he just entered
		slowText(getMap()->onEnterance(player), textSpeed);
	}
}

Npc getNpc(string name)
{
	for (Npc npc : getMap()->getNpcs()) {
		//Grabs the npc name
		string npcName = npc.getName();
		//Transforms all letters to lowercase
		transform(npcName.begin(), npcName.end(), npcName.begin(), ::tolower);
		//If the names dont match skip
		if (npcName != name) continue;
		//if name match return it
		return npc;
	}
	return Npc(1000);
}

Maps * getMap()
{
	return maps[player.getY()][player.getX()];
}

Maps * getMap(int x, int y)
{
	return maps[y][x];
}
