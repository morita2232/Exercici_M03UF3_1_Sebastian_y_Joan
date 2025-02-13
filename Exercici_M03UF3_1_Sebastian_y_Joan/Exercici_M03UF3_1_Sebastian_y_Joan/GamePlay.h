#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
//el gamplay.h sera la bibilioteca global para todo el codigo
//define usado para el tama�o tablero y el resto de operaciones booleanas y for's.
#define TAMA�O_TABLERO 3


void createTablero(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO]);
void renderTablero(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO]);
void checkTablero(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO], bool& empate, bool& ganador);
void comprobacionVictoria(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO], bool& ganador);
void gamePlay(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO], bool& gameOver);