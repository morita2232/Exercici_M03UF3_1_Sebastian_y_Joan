#include <iostream>
#include "Inicio.h"
#include "GamePlay.h"


void main() {
	char tablero[Tama�otablero][Tama�otablero];
	pantallaInicio(tablero);

	gamePlay(tablero);
	
	RenderTablero(tablero);

}