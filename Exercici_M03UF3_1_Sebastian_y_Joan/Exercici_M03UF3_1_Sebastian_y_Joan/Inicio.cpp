#include <iostream>
#include <string>
#include "GamePlay.h"

void pantallaInicio(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO], bool& gameOver) {
	//creacion de variables
	short opcio = 0;

	bool choice = false;

	std::string nombreArchivo, caracter;

	std::ifstream loadFile(nombreArchivo + ".tictacsave");

	//codigo del menu
	do {

		gameOver = false;

		std::cout << "---------- Tres en ratlla ----------" << std::endl;

		std::cout << std::endl;

		std::cout << "1 - Nova partida" << std::endl;
		std::cout << "2 - Carregar partida guardada" << std::endl;
		std::cout << "3 - Soritr" << std::endl;

		std::cout << std::endl;

		std::cout << "Tria una opcio (EN NUMEROS ENTRE EL 1 Y EL 3): ";
		std::cin >> opcio;
		//Escoger una opcion del menu
		switch (opcio) {
		case 1:
			std::cout << std::endl;

			std::cout << "Creando partida..." << std::endl;

			system("pause");
			system("cls");

			gameOver = false;

			//inicializacion del tablero
			createTablero(tablero);

			renderTablero(tablero);
			//Turnos del gameplay
			gamePlay(tablero, gameOver);

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

			//debug de inputs
			if (nombreArchivo == "menu" || nombreArchivo == "Menu" || nombreArchivo == "MENU") {
				system("cls");
				pantallaInicio(tablero,gameOver);
			}
			else {
				do {
					//abrimos el archivo escogido
					loadFile.open(nombreArchivo + ".tictacsave");
					if (loadFile.is_open()) {
						std::cout << "Cargando partida: " << nombreArchivo << std::endl;

						system("pause");
						system("cls");
						//inicializamos un tablero vacio para rellenarlo
						createTablero(tablero);

						int j = 0;

						while (std::getline(loadFile, caracter)) {
							for (int i = 0; i < TAMA�O_TABLERO; i++) {
								tablero[j][i] = caracter[i];
							}
							j++;
						}

						loadFile.close();
						renderTablero(tablero);
						//Seguir la partida guardada con el siguiente turno
						gamePlay(tablero, gameOver);

						choice = true;

					}
					else {
						std::cout << "Archivo no encontrado, dame otro nombre->";
						std::cin >> nombreArchivo;
					}
				} while (!choice);

			}

			break;

		case 3:
			//cerrar el juego
			std::cout << std::endl;

			std::cout << "Adeu!" << std::endl;

			choice = true;

			gameOver = true;

			break;

		default:

			system("cls");
		}
	} while (!choice);
}
