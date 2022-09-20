#ifndef Dialogue
#define Dialogue

#include "Player.h"
#include "Npc.h"
#include "TextHandler.h"
#include "Shops.h"
#include <algorithm>

string getDialogue(Player& player, Npc npc);
string handleStore(Player& player, Npc npc);

#endif