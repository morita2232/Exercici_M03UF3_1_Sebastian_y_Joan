#include <iostream>
#include "Inicio.h"
#include "GamePlay.h"


void main() {
	char tablero[Tamañotablero][Tamañotablero];
	pantallaInicio(tablero);

	gamePlay(tablero);
	
	RenderTablero(tablero);

}