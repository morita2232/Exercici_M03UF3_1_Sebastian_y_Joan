#include "GamePlay.h"
#include "Inicio.h"


void createTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]) {
    for (int i = 0; i < TAMAÑO_TABLERO; i++) {
        for (int j = 0; j < TAMAÑO_TABLERO; j++) {
            tablero[i][j] = ' ';
        }
    }
}


void renderTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]) {
    for (int i = 0; i < TAMAÑO_TABLERO; i++) {
        std::cout << "-------------\n";
        for (int j = 0; j < TAMAÑO_TABLERO; j++) {
            std::cout << '|'  << ' ' << tablero[i][j] << ' ';
        }
        std::cout << '|' << std::endl;
    }
        std::cout << "-------------\n";
    
}

void checkTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& empate, bool& ganador) {


    int contador = 0;

    int board_size = TAMAÑO_TABLERO * TAMAÑO_TABLERO;

    contador = 0;


        for (int i = 0; i < TAMAÑO_TABLERO; i++) {
            for (int j = 0; j < TAMAÑO_TABLERO; j++) {
                if (tablero[j][i] == 'X' || tablero[j][i] == 'O') {
                    contador++;
                }
            }
        }

        if (contador == board_size) {
            empate = true;
        }

}

void comprobacionVictoria(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& ganador) {
   /*
    int contador = 0;
    bool empate = false;
    
    int board_size = TAMAÑO_TABLERO * TAMAÑO_TABLERO;

    contador = 0;
    for (int i = 0; i < TAMAÑO_TABLERO; i++) {
        for (int j = 0; j < TAMAÑO_TABLERO; j++) {
            if (tablero[j][i] == 'X' || tablero[j][i] == 'O') {
                contador++;
                std::cout << "DEBUG: posicion " << j << ", " << i << ": " << tablero[j][i] << std::endl;
            }
        }
    }

    std::cout << "DEBUG: contador-> " << contador << std::endl;
    std::cout << "DEBUG: size-> " << board_size << std::endl;

    if (contador == board_size) {
        empate = true;
    }

    if (empate == true) {
        std::cout << "Empate!, reiniciando partida" << std::endl;

        system("pause");
        system("cls");

        createTablero(tablero);

    }
    */

   // else if (empate == false) {
         //true es Jugador y false la IA
        //filas y columnas
        for (int i = 0; i < TAMAÑO_TABLERO; i++) {
            if (tablero[i][0] != ' ' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
                if (tablero[i][0] == 'X') {
                    ganador = true;
                }
                else {
                    ganador = false;
                }
            }
            else if (tablero[0][i] != ' ' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
                if (tablero[0][i] == 'X') {
                    ganador = true;
                }
                else {
                    ganador = false;
                }
            }
        }
        //Diagonales
        if (tablero[0][0] != ' ' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
            if (tablero[0][0] == 'X') {
                ganador = true;
            }
            else {
                ganador = false;
            }
        }
        else if (tablero[2][0] != ' ' && tablero[2][0] == tablero[1][1] && tablero[1][1] == tablero[0][2]) {
            if (tablero[2][0] == 'X') {
                ganador = true;
            }
            else {
                ganador = false;
            }
        }
  // }
}

void gamePlay(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& gameOver) {

    bool ganador;
    bool empate = false;
    bool eleccion_archivo = false;
    short posx, posy;
    char input = 0;
    char sobreEscribir = 'a';
    std::string nameFile;

    while (!gameOver) {
        srand(time(NULL));

        input = 0;

        //std::cout << TAMAÑO_TABLERO * TAMAÑO_TABLERO << std::endl;

        std::cout << "Tu turno Jugador" << std::endl;
        std::cout << "Dame una posicion en x, y (ej. 0 2): ";
        std::cin >> posx >> posy;
        while (tablero[posy][posx] != ' ') {
            std::cout << "Posicion invalida, escoge otra :(\n>>";
            std::cin >> posx >> posy;
        }
        tablero[posy][posx] = 'X';
       
        checkTablero(tablero, empate, ganador);
        
        if (empate != true) {
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

                    do {
                        if (nameFile == "menu" || nameFile == "Menu" || nameFile == "MENU") {
                            std::cout << "No puedes escoger ese nombre, escoge otro ->";
                            std::cin >> nameFile;
                        }

                        else {
                            std::string archivoExistente = nameFile + ".tictacsave";

                            std::ifstream check(archivoExistente);

                            if (check.is_open()) {
                                check.close();

                                std::cout << "Este archivo ya existe, quieres sobreescribirlo? (y/n)" << std::endl;
                                std::cin >> sobreEscribir;
                            if (sobreEscribir != 'y' && sobreEscribir != 'Y') {
                                std::cout << "Dame otro nombre" << std::endl;
                                std::cin >> nameFile;
                            }
                            }

                            std::ofstream saveFile;

                            saveFile.open(nameFile + ".tictacsave", std::ios::out | std::ios::trunc);

                            if (saveFile.is_open()) {
                                for (int i = 0; i < TAMAÑO_TABLERO; i++) {
                                    for (int j = 0; j < TAMAÑO_TABLERO; j++) {
                                        saveFile << tablero[i][j];
                                    }
                                    saveFile << "\n";
                                }
                                saveFile.close();

                                std::cout << "Volviendo al menu principal!" << std::endl;

                                eleccion_archivo = true;

                                system("pause");
                                system("cls");

                                pantallaInicio(tablero, gameOver);
                            }
                            else {
                                std::cout << "hubo un error" << std::endl;
                            }
                        }
                    } while (!eleccion_archivo);
                    gameOver = true;
                }

                else /*if (input == 'n' || input == 'N')*/ {



                    system("pause");
                    system("cls");

                    comprobacionVictoria(tablero, ganador);

                    if (ganador == false) {
                        std::cout << "Jugador... Has Perdido!!!" << std::endl;
                        gameOver = true;
                    }

                    else if (ganador == true) {
                        std::cout << "Jugador... Has Ganado!!!" << std::endl;
                        gameOver = true;
                    }
                    renderTablero(tablero);


                }
            }

        }
        else if (empate == true) {
                std::cout << "Empate!, reiniciando partida" << std::endl;

                system("pause");
                system("cls");

                empate = false;
                eleccion_archivo = false;

                createTablero(tablero);

                renderTablero(tablero);

        }

    }
}