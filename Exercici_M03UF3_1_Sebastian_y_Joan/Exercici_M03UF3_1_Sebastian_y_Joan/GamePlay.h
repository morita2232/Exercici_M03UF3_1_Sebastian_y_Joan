#pragma once
#include <iostream>
#include <list>

#define Tamaņotablero 3


void Createtablero(char tablero[Tamaņotablero][Tamaņotablero]);
void RenderTablero(char tablero[Tamaņotablero][Tamaņotablero]);
bool ComprobacionVictoria(char tablero[Tamaņotablero][Tamaņotablero]);
void gamePlay(char tablero[Tamaņotablero][Tamaņotablero]);