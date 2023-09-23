#pragma warning (disable : 4996)
#include "Match.h"
#include <stdio.h>

Match::Match() : date(13, 2, 23), id(0), points{ 0, 0 }{
}

void Match::SaveGame(const char *saveFile) {
	SaveData data();

	FILE* fp = fopen(saveFile, "a");

	if (fp == nullptr) {
		perror("No se pudo abrir el archivo\n");
	}

	if (fwrite(&data, sizeof(SaveData), 1, fp) != 1) {
		perror("No se puede escribir.");
		fclose(fp);
	}

	fclose(fp);
}