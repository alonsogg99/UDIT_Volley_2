#pragma warning (disable : 4996)
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Match.h"
#include "Player.h"
#include "Ball.h"
using namespace std;

unsigned int CreateGame() {
	FILE* fp = fopen("gameIDs.csv", "r+");
	if (fp == nullptr) {
		fp = fopen("gameIDs.csv", "w+");
		if (fp == nullptr) {
			perror("No se pudo abrir el archivo\n");
			return 0;
		}
        fprintf(fp, 0);
	}
	unsigned int newid = 0;

	if (fscanf(fp, "%d", &newid) == 1) {
		newid++; fseek(fp, 0, SEEK_SET);
		fprintf(fp, "%d", newid);
		printf("ID de partida: %d\n", newid);
	}
	else printf("No se pudo leer el archivo.\n");

	fclose(fp);

	return newid;
}

void Load() {
	unsigned int id;
	cout << "Introduce el ID de la partida que deseas cargar.\n";
	cin >> id;
	Match match;
	match.LoadGame("saveFile.csv", id);
}

void SimulationMatch() {
	cout << "Partida simulada con exito\n";
	Match match;
	unsigned int p1, p2, d;
	srand(time(NULL));
	p1 = 25;
	p2 = rand() % 24;
    d = rand() % 268;
	match.setPoints1(p1);
	match.setPoints2(p2);
    match.setDuration(d);
	match.SaveGame("saveFile.csv", CreateGame(), match.getPoints1(), match.getPoints2(), match.getPlayer1(), match.getPlayer2(), match.getBall(), match.getDuration());
}

void MainMenu() {
	system("cls");
	unsigned int choice;
	cout << "UDIT VOLLEY\n";
	cout << "==================\n";
	cout << "1. Iniciar partida\n";
	cout << "2. Cargar partida\n";
	cout << "3. Simular partida\n";
	cout << "4. Partida en linea\n";
	cout << "5. Rankings\n";
	cout << "6. Salir\n";
	cin >> choice;
	if (choice < 7 && choice > 0) {
		switch (choice) {
			case 2:
				Load();
				break;
			case 3:
				SimulationMatch();
				break;
		}
	}

	else {
		cout << "Error, elige una opcion valida.\n";
		MainMenu();
	}
}

//Comprueba si el fichero existe y puede abrirse
bool file_exists(const char* filename) {
	FILE* fp = fopen(filename, "r");

	if (fp == NULL) return false;

	fclose(fp);

	return true;
}

//Devuelve el tamaño del fichero
uint32_t file_size(const char* filename) {
	struct stat st;
	if (stat(filename, &st) == 0) return st.st_size;

	return 0;
}

//Escribir en archivo de texto
/*bool write_to_file(const char* filename, string line) {
	if (file_exists(filename)) {
		FILE* fp = fopen(filename, "a");
		fp >> line;
		fclose(fp);
		return true;
	}

	else return false;
}

//Leer archivo de texto
bool read_from_file(const char* filename, string line) {
	if (file_exists(filename)) {
		FILE* fp = fopen(filename, "w");
		return true;
	}

	else return false;
}*/

int main(){
	MainMenu();
}