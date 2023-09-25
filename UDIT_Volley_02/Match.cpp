#pragma warning (disable : 4996)
#include "Match.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Match::Match() : id(0), points{ 0, 0 }{
}

void Match::SaveGame(const char *saveFile) {
	SaveData data(id, points, player, ball);

	FILE* fp = fopen(saveFile, "a");

	if (fp == nullptr) {
		perror("No se pudo abrir el archivo\n");
	}

	if (fp != NULL) {
		if (fwrite(&data, sizeof(SaveData), 1, fp) != 1) {
			perror("No se puede escribir.");
			fclose(fp);
		}
		cout << "Escritura realizada con exito";
	}

	else perror("Error, no se pudo leer el archivo");

	fclose(fp);
}