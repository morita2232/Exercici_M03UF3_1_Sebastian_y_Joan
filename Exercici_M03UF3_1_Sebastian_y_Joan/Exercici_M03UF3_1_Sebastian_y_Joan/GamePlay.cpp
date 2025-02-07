#include "GamePlay.h"

//TO DO
//true false
//nombre funciones


void Createtablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]) {
    for (int i = 0; i < TAMAÑO_TABLERO; i++) {
        for (int j = 0; j < TAMAÑO_TABLERO; j++) {
            tablero[i][j] = ' ';
        }
    }
}


void RenderTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]) {
    for (int i = 0; i < TAMAÑO_TABLERO; i++) {
        std::cout << "-------------\n";
        for (int j = 0; j < TAMAÑO_TABLERO; j++) {
            std::cout << '|'  << ' ' << tablero[i][j] << ' ';
        }
        std::cout << '|' << std::endl;
    }
        std::cout << "-------------\n";
    
}

void ComprobacionVictoria(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], short& ganador) {
    // true es Jugador y false la IA
    //filas y columnas
    for (int i = 0; i < TAMAÑO_TABLERO; i++) {
        if (tablero[i][0] != ' ' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            if (tablero[i][0] == 'X') {
                ganador = 1;
            }
            else {
                ganador = 0;
            }
        }
        else if (tablero[0][i] != ' ' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            if (tablero[0][i] == 'X') {
                ganador =  1;
            }
            else {
                ganador = 0;
            }
        }
    }
    //Diagonales
    if (tablero[0][0] != ' ' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        if (tablero[0][0] == 'X') {
            ganador = 1;
        }
        else {
            ganador = 0;
        }
    }
    else if (tablero[2][0] != ' ' && tablero[2][0] == tablero[1][1] && tablero[1][1] == tablero[0][2]) {
        if (tablero[2][0] == 'X') {
            ganador = 1;
        }
        else {
            ganador = 0;
        }
    }
}

void gamePlay(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& gameOver) {

    short ganador = 2;
    short posx, posy;
    char input = 0;
    std::string nameFile;

    while (!gameOver) {
        srand(time(NULL));

        input = 0;

        std::cout << "Tu turno Jugador" << std::endl;
        std::cout << "Dame una posicion en x, y (ej. 0 2): ";
        std::cin >> posx >> posy;
        while (tablero[posy][posx] != ' ') {
            std::cout << "Posicion invalida, escoge otra :(\n>>";
            std::cin >> posx >> posy;
        }
        tablero[posy][posx] = 'X';
        std::cout << "La IA ya ha hecho su movimiento\n";
        posx = rand() % 3;
        posy = rand() % 3;
        while (tablero[posy][posx] != ' ') {
            posx = rand() % 3;
            posy = rand() % 3;
        }
        tablero[posy][posx] = 'O';


        while (input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
            std::cout << "Quieres guardar partida?? (Y/N)" << std::endl;
            std::cin >> input;
            if (input == 'y' || input == 'Y') {
                // guardado

                std::cout << "Como quieres que se llame al archivo??" << std::endl;
                std::cin >> nameFile;

                std::ofstream saveFile;

                saveFile.open(nameFile + ".tictacsave", std::ios::out | std::ios::trunc);

                if (saveFile.is_open()) {
                    for (int i = 0; i < TAMAÑO_TABLERO; i++) {
                        for (int j = 0; j < TAMAÑO_TABLERO; j++) {
                            saveFile << tablero[i][j];
                        }
                        //std::cout << "\n";
                    }
                }
                else {
                    std::cout << "hubo un error" << std::endl;
                }
                saveFile.close();
                gameOver = true;
            }

            else if (input == 'n' || input == 'N') {



                system("pause");
                system("cls");

                ComprobacionVictoria(tablero, ganador);

                if (ganador == 0) {
                    std::cout << "Jugador... Has Perdido!!!" << std::endl;
                    gameOver = true;
                }

                else if (ganador == 1) {
                    std::cout << "Jugador... Has Ganado!!!" << std::endl;
                    gameOver = true;
                }

                RenderTablero(tablero);

            }
        }
    }
}