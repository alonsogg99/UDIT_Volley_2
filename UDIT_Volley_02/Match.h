#pragma once
#include "Player.h"
#include "Ball.h"

struct SaveData {
	unsigned char id;
	unsigned char points[2] ;
	Player player[2];
	Ball ball;

	//Constructor
	SaveData(unsigned char i, unsigned char p[2], Player pl[2], Ball b) : id(i), ball(b) {
		for (int j = 0; j < 2; j++) {
			points[j] = p[j];
			player[j] = pl[j];
		}
	}
};

class Match{
private:
	unsigned char id = 0;
	unsigned char points[2] = { 0,0 };
	Player player[2];
	Ball ball;
public:
	Match();
	void SaveGame(const char *saveFile);
};