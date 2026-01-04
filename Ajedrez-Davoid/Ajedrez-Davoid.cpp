#include <iostream>
#define N 8
using namespace std;

int turno = 0;

void creartablero(char tablero[N][N]) {
    // Letras del tablero
    char letras[N][N] = {
        {'t','h','b','k','q','b','h','t'},
        {'p','p','p','p','p','p','p','p'},
        {'*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*'},
        {'P','P','P','P','P','P','P','P'},
        {'T','H','B','Q','K','B','H','T'}
    };

    //Asignacion de las letras al tablero cuando lo creamos
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tablero[i][j] = letras[i][j];
        }
    }
}

bool moverPeon(char tablero[N][N], int fi, int ci, int ff, int cf) {
    char peon = tablero[fi][ci];

    // PEÓN BLANCO
    if (peon == 'P' && turno % 2 == 0) {

        // Movimiento normal
        if (ff == fi - 1 && cf == ci && tablero[ff][cf] == '*') {
            tablero[ff][cf] = 'P';
            tablero[fi][ci] = '*';
            return true;
        }

        // Doble movimiento inicial
        if (fi == 6 && ff == fi - 2 && cf == ci &&
            tablero[fi - 1][ci] == '*' &&
            tablero[ff][cf] == '*') {

            tablero[ff][cf] = 'P';
            tablero[fi][ci] = '*';
            return true;
        }
    }

    // PEÓN NEGRO
    if (peon == 'p' && turno % 2 != 0) {

        // Movimiento normal
        if (ff == fi + 1 && cf == ci && tablero[ff][cf] == '*') {
            tablero[ff][cf] = 'p';
            tablero[fi][ci] = '*';
            return true;
        }

        // Doble movimiento inicial
        if (fi == 1 && ff == fi + 2 && cf == ci &&
            tablero[fi + 1][ci] == '*' &&
            tablero[ff][cf] == '*') {

            tablero[ff][cf] = 'p';
            tablero[fi][ci] = '*';
            return true;
        }
    }

    return false;
}

bool moverFicha(char tablero[N][N]) {
    int fi, ci, ff, cf;
    
    //comprovacion de turno inicial
    cout << (turno % 2 == 0 ? "Turno BLANCAS\n" : "Turno NEGRAS\n");

    //pedimas al usuario que ficha quiere mover
    cout << "Fila origen: ";
    cin >> fi;
    cout << "Columna origen: ";
    cin >> ci;

    //pedimos al usuario a donde quiere mover la ficha selecionada
    cout << "Fila destino: ";
    cin >> ff;
    cout << "Columna destino: ";
    cin >> cf;

    //calculos de movimientos
    fi = N - fi;
    ff = N - ff;
    ci--;
    cf--;

    //posicion de la ficha
    char pieza = tablero[fi][ci];

    if (pieza == '*') {
        cout << "No hay pieza ahi\n";
        return false;
    }

    if (pieza == 'P' || pieza == 'p') {
        return moverPeon(tablero, fi, ci, ff, cf);
    }


    return false;
}

void printtablero(char tablero[N][N]) {

    //Numeros superiores
    std::cout << "  ";
    for (int i = 1; i <= N; i++) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // Imprimir tablero con numeros a la izquierda
    for (int i = 0; i < N; i++) {
        std::cout << (N - i) << ' ';
        for (int j = 0; j < N; j++) {
            std::cout << tablero[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    char tablero[N][N];
    creartablero(tablero);

    bool gameover = false;
    while (!gameover) {
        printtablero(tablero);

        if (moverFicha(tablero)) {
            turno++; 
        }

        system("cls");
    }

    return 0;
}
