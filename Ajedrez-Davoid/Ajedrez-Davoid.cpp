#include <iostream>

#include "Func.h"

using namespace std;
int turno = 0;
// si no lo ves tienes un txt en "Archivos de recursos" si no entiendes alguna cosa


void creartablero(char tablero[N][N]) {
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

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tablero[i][j] = letras[i][j];
        }
    }
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

    if (pieza == 'T' || pieza == 't') {
        return moverTorre(tablero, fi, ci, ff, cf);
    }

    if (pieza == 'H' || pieza == 'h') {
        return moverCaballo(tablero, fi, ci, ff, cf);
    }
    if (pieza == 'B' || pieza == 'b') {
        return moverAlfil(tablero, fi, ci, ff, cf);
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
