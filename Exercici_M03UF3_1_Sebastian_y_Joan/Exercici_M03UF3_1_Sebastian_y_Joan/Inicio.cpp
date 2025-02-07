#include <iostream>
#include <string>
#include "GamePlay.h"

void pantallaInicio(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& gameOver) {

	short opcio = 0;

	bool choice = false;

	std::string nombreArchivo, caracter;

	std::ifstream loadFile(nombreArchivo + ".tictacsave");

	do {

		std::cout << "---------- Tres en ratlla ----------" << std::endl;

		std::cout << std::endl;

		std::cout << "1 - Nova partida" << std::endl;
		std::cout << "2 - Carregar partida guardada" << std::endl;
		std::cout << "3 - Soritr" << std::endl;

		std::cout << std::endl;

		std::cout << "Tria una opcio (EN NUMEROS ENTRE EL 1 Y EL 3): ";
		std::cin >> opcio;

		switch (opcio) {
		case 1:
			std::cout << std::endl;

			std::cout << "Creando partida..." << std::endl;

			system("pause");
			system("cls");

			gameOver = false;

			Createtablero(tablero);

			RenderTablero(tablero);

			choice = true;

			break;

		case 2:
			system("pause");
			system("cls");

			std::cout << "---------- Cargar paritda ----------" << std::endl;

			std::cout << std::endl;

			std::cout << "Cual es el nombre del archivo?" << std::endl;

			std::cout << std::endl;

			std::cin >> nombreArchivo;

			std::cout << std::endl;	

			loadFile.open(nombreArchivo + ".tictacsave");

			if (loadFile.is_open()) {
				std::cout << "Cargando partida: " << nombreArchivo << std::endl;

				system("pause");
				system("cls");

				Createtablero(tablero);

				while (std::getline(loadFile, caracter)) {
					int j = 0;
					for (int i = 0; i < TAMAÑO_TABLERO; i++) {
						tablero[j][i] = caracter[i];
					}
					j++;
				}


			}

			RenderTablero(tablero);
			choice = true;


			break;

		case 3:
			std::cout << "Adeu!" << std::endl;

			choice = true;

			gameOver = true;

			break;

		default:

			system("cls");
		}
	} while (!choice);
}
