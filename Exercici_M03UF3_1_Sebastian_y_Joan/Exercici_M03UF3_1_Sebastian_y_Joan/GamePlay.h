#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
//el gamplay.h sera la bibilioteca global para todo el codigo
//define usado para el tamaño tablero y el resto de operaciones booleanas y for's.
#define TAMAÑO_TABLERO 3


void createTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]);
void renderTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]);
void checkTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& empate, bool& ganador);
void comprobacionVictoria(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& ganador);
void gamePlay(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& gameOver);