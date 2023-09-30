#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
	short x = 0, y = 0;
	char id = 0;
	string name;
public:
	Player();
	void Move();
	void Jump();
    short getPosX();
    short getPosY();
	char getId();
	string getName();
	void setId(char i);
	void setName(string n);
};

