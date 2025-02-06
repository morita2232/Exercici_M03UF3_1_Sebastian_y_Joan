#include "GamePlay.h"

void Createtablero(char tablero[Tamañotablero][Tamañotablero]) {
    for (int i = 0; i < Tamañotablero; i++) {
        for (int j = 0; j < Tamañotablero; j++) {
            tablero[i][j] = ' ';
        }
    }
}


void RenderTablero(char tablero[Tamañotablero][Tamañotablero]) {
    for (int i = 0; i < Tamañotablero; i++) {
        std::cout << "-------------\n";
        for (int j = 0; j < Tamañotablero; j++) {
            std::cout << '|'  << ' ' << tablero[i][j] << ' ';
        }
        std::cout << '|' << std::endl;
    }
        std::cout << "-------------\n";
    
}

bool ComprobacionVictoria(char tablero[Tamañotablero][Tamañotablero]) {
    // true es Jugador y false la IA
    //filas y columnas
    for (int i = 0; i < Tamañotablero; i++) {
        if (tablero[i][0] != ' ' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            if (tablero[i][0] == 'X') {
                return true;
            }
            else {
                return false;
            }
        }
        else if (tablero[0][i] != ' ' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            if (tablero[0][i] == 'X') {
                return true;
            }
            else {
                return false;
            }
        }
    }
    //Diagonales
    if (tablero[0][0] != ' ' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        if (tablero[0][0] == 'X') {
            return true;
        }
        else {
            return false;
        }
    }
    else if (tablero[2][0] != ' ' && tablero[2][0] == tablero[1][1] && tablero[1][1] == tablero[0][2]) {
        if (tablero[2][0] == 'X') {
            return true;
        }
        else {
            return false;
        }
    }
}

void gamePlay(char tablero[Tamañotablero][Tamañotablero]) {

    bool gameOver = false;
    short posx, posy;

    do {
        srand(time(NULL));

        std::cout << "Tu turno Jugador" << std::endl;
        std::cout << "Dame una posicion en x, y (ej. 0 2): ";
        std::cin >> posx >> posy;
        while (tablero[posy][posx] != ' ') {
            std::cout << "Posicion invalida, escoge otra :(\n>>";
            std::cin >> posx >> posy;
        }
        tablero[posy][posx] = 'X';
        if (ComprobacionVictoria(tablero)) {
            std::cout << "Jugador... ¡¡¡Has Ganado!!!" << std::endl;
            gameOver = true;
        }
        std::cout << "La IA ya ha hecho su movimiento\n";
        posx = rand() % 3;
        posy = rand() % 3;
        while(tablero[posy][posx] != ' ') {
            posx = rand() % 3;
            posy = rand() % 3;
        }
        tablero[posy][posx] = 'O';
        
        system("pause");
        system("cls");
        if (!ComprobacionVictoria(tablero)) {
            std::cout << "Jugador... ¡¡¡Has Perdido!!!" << std::endl;
            gameOver = true;
        }
        RenderTablero(tablero);
    } while (!gameOver);
}