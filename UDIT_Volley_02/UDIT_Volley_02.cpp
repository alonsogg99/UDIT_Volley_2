#pragma warning (disable : 4996)
#include <iostream>
#include "Match.h"
#include "Player.h"
#include "Ball.h"
using namespace std;

void SimulationMatch() {
	Match match;
	match.SaveGame("saveFile.dat");
}

void MainMenu() {
	system("cls");
	unsigned char choice = 0;
	cout << "UDIT VOLLEY\n";
	cout << "==================\n";
	cout << "1. Iniciar partida\n";
	cout << "2. Cargar partida\n";
	cout << "3. Simular partida\n";
	cout << "4. Partida en línea\n";
	cout << "5. Rankings\n";
	cout << "6. Salir\n";
	cin >> choice;
	if (choice < 7 && choice > 0) {
		switch (choice) {
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