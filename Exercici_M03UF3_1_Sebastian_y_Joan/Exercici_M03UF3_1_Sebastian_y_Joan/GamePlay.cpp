#include "GamePlay.h"

void Createtablero(char tablero[Ytablero][Xtablero]) {
    for (int i = 0; i < Ytablero; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < Xtablero; j++) {
                tablero[i][j] = '-';
            }
        }
        else {

            for (int j = 0; j < Xtablero; j++) {
                if (j % 4 == 0) {
                    tablero[i][j] = '|';
                }
                else {
                    tablero[i][j] = ' ';
                }
            }
        }
    }
}


void RenderTablero(char tablero[Ytablero][Xtablero]) {
	for (int i = 0; i < Ytablero; i++) {
		for (int j = 0; j < Xtablero; j++) {
			std::cout << tablero[i][j];
		}
		std::cout << std::endl;
	}
}

void gamePlay() {




}