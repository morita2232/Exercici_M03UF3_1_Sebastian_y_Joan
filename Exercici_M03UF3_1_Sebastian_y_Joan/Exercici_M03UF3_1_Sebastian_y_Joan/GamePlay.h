#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>

#define TAMAÑO_TABLERO 3


void Createtablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]);
void RenderTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]);
void ComprobacionVictoria(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], short& ganador);
void gamePlay(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& gameOver);