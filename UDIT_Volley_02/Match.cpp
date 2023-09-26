#pragma warning (disable : 4996)
#include "Match.h"
#include <stdio.h>
#include <iostream>
using namespace std;

struct SaveData {
	unsigned int id = 0;
	unsigned int points[2] = {0,0};
	Player player[2];
	Ball ball;
}matchData;

Match::Match() : id(0), points{ 0, 0 } {
}

unsigned int Match::getId() {
	return id;
}

unsigned int Match::getPoints1() {
	return points[0];
}

unsigned int Match::getPoints2() {
	return points[1];
}

Player Match::getPlayer1() {
	return player[0];
}

Player Match::getPlayer2() {
	return player[1];
}

Ball Match::getBall() {
	return ball;
}

void Match::LoadGame(const char* saveFile, unsigned int gameid) {
	FILE* fp = fopen(saveFile, "r");

	if (fp == nullptr) {
		perror("No se pudo abrir el archivo\n");
	}

	char line[256];
	char search[256];
	bool found = false;
	sprintf(search, "Player ID: %u", gameid);
	char first_data[256];
	char second_data[256];

	if (fp != 0){
		while (fgets(line, sizeof(line), fp)) {
			if (strstr(line, search) != NULL) {
				printf(line);
				found = true;
				fclose(fp);
				break;
			}
		}
	}
	fclose(fp);
}

void Match::SaveGame(const char* saveFile, unsigned int i, unsigned int p1, unsigned int p2, Player pj1, Player pj2, Ball b) {
	matchData.id = i;
	matchData.points[0] = p1;
	matchData.points[1] = p2;
	matchData.player[0] = pj1;
	matchData.player[1] = pj2;
	matchData.ball = b;


	FILE* fp = fopen(saveFile, "a");

	if (fp == nullptr) {
		perror("No se pudo abrir el archivo\n");
	}

	if (fp != NULL) {
		char buffer[256];
		sprintf(buffer, "Player ID: %d\nPlayer01 Points: %d\nPlayer02 Points: %d\n", matchData.id, matchData.points[0], matchData.points[1]);
		fputs(buffer, fp);
		cout << "Escritura realizada con exito\n";
	}

	else perror("Error, no se pudo leer el archivo");

	fclose(fp);
}