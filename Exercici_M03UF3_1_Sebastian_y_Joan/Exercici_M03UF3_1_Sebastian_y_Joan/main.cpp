#include <iostream>
#include "Inicio.h"
#include "GamePlay.h"


void main() {
	char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO];

	bool gameOver = false;

	pantallaInicio(tablero, gameOver);

	gamePlay(tablero, gameOver);

}