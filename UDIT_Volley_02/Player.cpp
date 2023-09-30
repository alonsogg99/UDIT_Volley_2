#include "Player.h"
#include <stdio.h>
#include <iostream>
#include <string>

Player::Player() {

}

short Player::getPosX() { return x; }

short Player::getPosY() { return y; }

char Player::getId() { return id; }

string Player::getName() { return name; }

void Player::setId(char i) { id = i; }

void Player::setName(std::string n) { name = n; }

void Player::Move() {

}
void Player::Jump() {

}
