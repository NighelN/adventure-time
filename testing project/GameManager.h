#ifndef GameManager
#define GameManager

#include "Dialogue.h"
#include "Combat.h"
#include "Player.h"
#include "TextHandler.h"
#include "Maps.h"
#include "Tutorial.h"
#include "Mensfield.h"
#include "Church.h"
#include "Forest.h"
#include "Shed.h"
#include "FisherKingdom.h"
#include "FishingDock.h"
#include "FishingStore.h"
#include "WeaponStore.h"
#include "Dungeon.h"
#include "Dungeon_one.h"
#include "Dungeon_two.h"
#include "Ironforge.h"
#include "Sharnwick.h"
#include "MedicineStore.h"
#include "Path.h"
#include "Empty.h"
#include "Cooking.h"
#include "Fishing.h"
#include "Woodcutting.h"
#include "Firemaking.h"
#include <string>
#include "windows.h"
#include <algorithm>

void menu();
void start();
void run();
void handleCommands(string command);
void travel(string direction);
Npc getNpc(string name);
Maps* getMap();
Maps* getMap(int x, int y);

#endif