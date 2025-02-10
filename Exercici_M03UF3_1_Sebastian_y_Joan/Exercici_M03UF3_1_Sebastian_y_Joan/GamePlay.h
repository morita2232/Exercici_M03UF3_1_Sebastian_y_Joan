#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>

#define TAMAÑO_TABLERO 3


void createTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]);
void renderTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]);
void checkTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& empate, bool& ganador);
void comprobacionVictoria(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& ganador);
void gamePlay(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& gameOver);