#include <iostream>
#include "Inicio.h"
#include "GamePlay.h"


void main() {
	char tablero[Tamaņotablero][Tamaņotablero];
	pantallaInicio(tablero);

	gamePlay(tablero);
	
	RenderTablero(tablero);

}