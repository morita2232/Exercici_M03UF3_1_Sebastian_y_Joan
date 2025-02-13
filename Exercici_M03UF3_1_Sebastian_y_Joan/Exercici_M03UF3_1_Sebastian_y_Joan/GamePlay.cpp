#include "GamePlay.h"
#include "Inicio.h"

//funcion de inicilizacion del tablero vacio
void createTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]) {
    for (int i = 0; i < TAMAÑO_TABLERO; i++) {
        for (int j = 0; j < TAMAÑO_TABLERO; j++) {
            tablero[i][j] = ' ';
        }
    }
}

//funcion de renderizado de tablero
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

//funcion para comprobar tablero lleno
void checkTablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& empate, bool& ganador) {

    int contador = 0;

    int board_size = TAMAÑO_TABLERO * TAMAÑO_TABLERO;// ya que sabemos que el tablero siempre sera quadrado, el tamaño total sera el area.

    contador = 0;

    // por cada pieza colocada el contador sumara uno.
    for (int i = 0; i < TAMAÑO_TABLERO; i++) {
        for (int j = 0; j < TAMAÑO_TABLERO; j++) {
            if (tablero[j][i] == 'X' || tablero[j][i] == 'O') {
                contador++;
            }
        }
    }
    //en e caso de que el contador coincida con el area del rtablero significara que esta lleno y sewra empate.
    if (contador == board_size) {
        empate = true;
    }

}

//funcion para comprobar al ganador de la partida mediante un booleano, si es true es el jugador si es false es la IA
void comprobacionVictoria(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& ganador) {
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

//funcion de sistema de turnos
void gamePlay(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO], bool& gameOver) {
    //creacion variables gameplay
    bool ganador;
    bool empate = false;
    bool eleccion_archivo = false;
    short posx, posy;
    char input = 0;
    char sobreEscribir = 'a';
    std::string nameFile;

    //inicio del bucle del juego
    while (!gameOver) {
        srand(time(NULL));

        input = 0;

        //Logica de jugador
        std::cout << "Tu turno Jugador" << std::endl;
        std::cout << "Dame una posicion en x, y (ej. 0 2): ";
        std::cin >> posx >> posy;
        //hasta que le jugador no escoga una posicion libre...
        while (tablero[posy][posx] != ' ') {
            std::cout << "Posicion invalida, escoge otra :(\n>>";
            std::cin >> posx >> posy;
        }
        tablero[posy][posx] = 'X';
        //miramos si el tablero esta lleno para evitar que la IA intente añadir una pieza en el tablero en caso "true".
        checkTablero(tablero, empate, ganador);
        
        //Logica de IA
        if (empate != true) {
            //randomizado de la eleccion IA
            std::cout << "La IA ya ha hecho su movimiento\n";
            posx = rand() % 3;
            posy = rand() % 3;
            //mientras la randomizacion no coincida con una casilla libre...
            while (tablero[posy][posx] != ' ') {
                posx = rand() % 3;
                posy = rand() % 3;
            }
            tablero[posy][posx] = 'O';


            //Guardado de patida
            while (input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
                std::cout << "Quieres guardar partida?? (Y/N)" << std::endl;
                std::cin >> input;
                if (input == 'y' || input == 'Y') {
                    // guardado

                    std::cout << "Como quieres que se llame al archivo??" << std::endl;
                    std::cin >> nameFile;

                    do {
                        //debug de input
                        if (nameFile == "menu" || nameFile == "Menu" || nameFile == "MENU") {
                            std::cout << "No puedes escoger ese nombre, escoge otro ->";
                            std::cin >> nameFile;
                        }
                        //en caso de que el input se permita se guardaran los datos.
                        else {
                            std::string archivoExistente = nameFile + ".tictacsave";

                            std::ifstream check(archivoExistente);
                            //debug de archivo abierto y de en caso de que el archivo ya exista.
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
                            //abrimos el archivo
                            saveFile.open(nameFile + ".tictacsave", std::ios::out | std::ios::trunc);
                            //una vez abierto se guardara el tablero por trea carateres un salto de linea.
                            if (saveFile.is_open()) {
                                for (int i = 0; i < TAMAÑO_TABLERO; i++) {
                                    for (int j = 0; j < TAMAÑO_TABLERO; j++) {
                                        saveFile << tablero[i][j];
                                    }
                                    saveFile << "\n";
                                }
                                saveFile.close();

                                std::cout << "Volviendo al menu principal!" << std::endl;

                                //una vez guardado el archivo salimos del bucle de guardado y volvemos al menu
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

                else  {  // en caso de no querer guardar partida (input != y).
                    //avance de turno


                    system("pause");
                    system("cls");
                    //comprobamos al ganador una vez acabado el turno
                    comprobacionVictoria(tablero, ganador);

                    //mensaje del ganador dependiendo del resultado de la funcion.
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
            //bucle de juego en caso de no tener ganador, se reinicia el tablero.
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