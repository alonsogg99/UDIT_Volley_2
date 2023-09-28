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
    unsigned int duration = 0;
}matchData;

Match::Match() : id(0), points{ 0, 0 } {}

unsigned int Match::getId() { return id; }

unsigned int Match::getPoints1() { return points[0]; }

unsigned int Match::getPoints2() { return points[1]; }

Player Match::getPlayer1() { return player[0]; }

Player Match::getPlayer2() { return player[1]; }

Ball Match::getBall() { return ball; }

void Match::setPoints1(unsigned int p) { points[0] = p; }

void Match::setPoints2(unsigned int p) { points[1] = p; }

unsigned int Match::getDuration() { return duration; }

void Match::setDuration(unsigned int d) { duration = d; }


void Match::LoadGame(const char* saveFile, unsigned int gameid) {
	FILE* fp = fopen(saveFile, "r");

	if (fp == nullptr) perror("No se pudo abrir el archivo\n");

	bool found = false;

	if (fp != 0){
		while (fscanf(fp, "Match ID: %d; %d; %d; ", &matchData.id, &matchData.points[0], &matchData.points[1])) {
			if (matchData.id == gameid) {
				printf("ID: %d\n", matchData.id);
				printf("Puntos J1: %d\n", matchData.points[0]);
				printf("Puntos J2: %d\n", matchData.points[1]);
                printf("Posicion del Jugador 1: %d en x, %d en y.\n", matchData.player[0].getPosX(), matchData.player[0].getPosY());
                printf("Posicion del Jugador 2: %d en x, %d en y.\n", matchData.player[1].getPosX(), matchData.player[1].getPosY());
                printf("Posicion de la Bola: %d en x, %d en y.\n", matchData.ball.getPosX(), matchData.ball.getPosY());
                printf("Duracion de la partida: %d segundos.\n", matchData.duration);
				found = true;
				break;
			}
		}
		if (!found) printf("ID no encontrado en el archivo.\n");
	}
	fclose(fp);
}

void Match::SaveGame(const char* saveFile, unsigned int i, unsigned int p1, unsigned int p2, Player pj1, Player pj2, Ball b, unsigned int d) {
	matchData.id = i;
	matchData.points[0] = p1;
	matchData.points[1] = p2;
	matchData.player[0] = pj1;
	matchData.player[1] = pj2;
	matchData.ball = b;
    matchData.duration = d;

	FILE* fp = fopen(saveFile, "a");

	if (fp == nullptr) {
		perror("No se pudo abrir el archivo\n");
	}

	if (fp != NULL) {
		char buffer[256];
		sprintf(buffer, "Match ID: %d; %d; %d; ", matchData.id, matchData.points[0], matchData.points[1]);
		fputs(buffer, fp);
		cout << "Escritura realizada con exito\n";
	}

	else perror("Error, no se pudo leer el archivo");

	fclose(fp);
}