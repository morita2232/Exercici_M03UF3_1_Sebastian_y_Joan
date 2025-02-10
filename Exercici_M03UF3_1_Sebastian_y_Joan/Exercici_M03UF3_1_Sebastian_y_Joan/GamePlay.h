#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>

#define TAMA�O_TABLERO 3


void createTablero(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO]);
void renderTablero(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO]);
void checkTablero(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO], bool& empate, bool& ganador);
void comprobacionVictoria(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO], bool& ganador);
void gamePlay(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO], bool& gameOver);