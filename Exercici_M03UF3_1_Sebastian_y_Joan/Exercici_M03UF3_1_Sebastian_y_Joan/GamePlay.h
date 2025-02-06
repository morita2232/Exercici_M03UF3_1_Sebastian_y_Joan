#pragma once
#include <iostream>
#include <list>

#define Tamañotablero 3


void Createtablero(char tablero[Tamañotablero][Tamañotablero]);
void RenderTablero(char tablero[Tamañotablero][Tamañotablero]);
bool ComprobacionVictoria(char tablero[Tamañotablero][Tamañotablero]);
void gamePlay(char tablero[Tamañotablero][Tamañotablero]);