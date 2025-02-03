#include <iostream>
#include <string>
#include "GamePlay.h"

void pantallaInicio() {

	short opcio;

	std::string nombreArchivo;

	char tablero[Ytablero][Xtablero];


	std::cout << "---------- Tres en ratlla ----------" << std::endl;

	std::cout << std::endl;

	std::cout << "1 - Nova partida" << std::endl;
	std::cout << "2 - Carregar partida guardada" << std::endl;
	std::cout << "3 - Soritr" << std::endl;

	std::cout << std::endl;

	std::cout << "Tria una opcio: ";
	std::cin >> opcio;

	switch (opcio) {
	case 1:
		std::cout << std::endl;

		std::cout << "Creando partida..." << std::endl;
		
		system("pause");
		system("cls");

		Createtablero(tablero);

		RenderTablero(tablero);
		
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

		std::cout << "Cargando partida: " << nombreArchivo << std::endl;

		break;

	case 3:
		std::cout << "Adeu!" << std::endl;
		break;
	}

}