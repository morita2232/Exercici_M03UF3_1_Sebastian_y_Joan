#include <iostream>
#include "Inicio.h"
#include "GamePlay.h"


void main() {
	char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO];

	bool gameOver = false;

	pantallaInicio(tablero, gameOver);

	gamePlay(tablero, gameOver);

}