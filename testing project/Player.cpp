#include "pch.h"
#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
	this->clear();
}


Player::~Player()
{
}

void Player::clear()
{
	this->getInventory().clear();
	this->tutorialStage = 0;
	this->skipTutorial = false;
	this->playerHealth = 10;
	this->move(2, 2);
}

Inventory& Player::getInventory()
{
	return this->inventory;
}

void Player::setHealth(int health)
{
	this->playerHealth = health;
	//Checks if the new player health is higher then 10
	if (this->playerHealth > 10)
		//Sets it back to 10
		this->playerHealth = 10;
}

int Player::getHealth()
{
	return this->playerHealth;
}

int Player::getX()
{
	return this->x;
}

int Player::getY()
{
	return this->y;
}

void Player::move(int x, int y) {
	this->x = x;
	this->y = y;
	this->hasFire = false;
}

int Player::getDamage(string weapon)
{
	if (weapon == "Fist" || weapon == "Feet") {
		return 100;
	}
	else if (weapon == "Axe") {
		return 2;
	}
	else if (weapon == "Wooden sword") {
		return 3;
	}
	else if (weapon == "Stone sword") {
		return 5;
	}
	return 0;
}
