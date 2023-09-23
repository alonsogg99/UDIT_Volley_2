#pragma once
#include "Player.h"
#include "Ball.h"

struct Date {
	int day;
	int month;
	int year;

	//Constructor
	Date(int d, int m, int y): day(d), month(m), year (y){}
};

struct SaveData {
	Date date;
	unsigned char id;
	unsigned char points[2] ;
	Player player[2];
	Ball ball;

	//Constructor
	SaveData(Date d, unsigned char i, unsigned char p[2], Player pl[2], Ball b) : date(d), id(i), ball(b) {
		for (int j = 0; j < 2; j++) {
			points[j] = p[j];
			player[j] = pl[j];
		}
	}
};

class Match{
private:
	Date date;
	unsigned char id = 0;
	unsigned char points[2] = { 0,0 };
	Player player[2];
	Ball ball;
public:
	Match();
	void SaveGame(const char *saveFile);
};