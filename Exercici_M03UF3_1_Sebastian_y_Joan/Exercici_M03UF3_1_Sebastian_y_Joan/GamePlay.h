#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>

#define TAMA�O_TABLERO 3


void Createtablero(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO]);
void RenderTablero(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO]);
void ComprobacionVictoria(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO], short& ganador);
void gamePlay(char tablero[TAMA�O_TABLERO][TAMA�O_TABLERO], bool& gameOver);