#pragma once
#include "Player.h"
#include "Ball.h"

class Match{
private:
	unsigned int id = 0;
    unsigned int duration = 0;
	unsigned int points[2] = { 0,0 };
	Player player[2];
	Ball ball;
public:
	Match();
	void SaveGame(const char *saveFile, unsigned int id, unsigned int points1, unsigned int points2, Player player1, Player player2, Ball ball, unsigned int duration);
	void LoadGame(const char* saveFile, unsigned int gameid);
	unsigned int getId();
	unsigned int getPoints1();
	unsigned int getPoints2();
	Player getPlayer1();
	Player getPlayer2();
	Ball getBall();
	void setPoints1(unsigned int p);
	void setPoints2(unsigned int p);
	void setPlayer1(char i, string n);
	void setPlayer2(char i, string n);
    unsigned int getDuration();
    void setDuration(unsigned int d);
};