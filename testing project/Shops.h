#ifndef Shops
#define Shops

#include "Player.h"
#include "TextHandler.h"
#include "Item.h"
#include <list>
#include <algorithm>

void openShop(Player& player, int npcId);
void handleInput(Player& player);
bool exists(string name);
void remove(Player& player, string name);
int getPrice(string name);

#endif