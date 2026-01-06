#include "Func.h"


bool moverPeon(char tablero[N][N], int fi, int ci, int ff, int cf) {
    char peon = tablero[fi][ci];
    // peon blanco
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

        // Captura de peon
        if (ff == fi - 1 && (cf == ci - 1 || cf == ci + 1) &&
            tablero[ff][cf] >= 'a' && tablero[ff][cf] <= 'z') {

            tablero[ff][cf] = 'P';
            tablero[fi][ci] = '*';
            return true;
        }
    }
    // peon negro
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

        // Captura de ficha
        if (ff == fi + 1 && (cf == ci - 1 || cf == ci + 1) &&
            tablero[ff][cf] >= 'A' && tablero[ff][cf] <= 'Z') {

            tablero[ff][cf] = 'p';
            tablero[fi][ci] = '*';
            return true;
        }
    }
    return false;
}

bool moverTorre(char tablero[N][N], int fi, int ci, int ff, int cf) {
    if (fi == ff && ci == cf) return false;

    char torre = tablero[fi][ci];

    // Turno correcto
    if ((torre == 'T' && turno % 2 != 0) ||
        (torre == 't' && turno % 2 == 0)) {
        return false;
    }

    // Solo fila o columna
    if (fi != ff && ci != cf) {
        return false;
    }

    // Vertical
    if (ci == cf) {
        int paso = (ff > fi) ? 1 : -1;
        for (int i = fi + paso; i != ff; i += paso) {
            if (tablero[i][ci] != '*') return false;
        }
    }

    // Horizontal
    if (fi == ff) {
        int paso = (cf > ci) ? 1 : -1;
        for (int j = ci + paso; j != cf; j += paso) {
            if (tablero[fi][j] != '*') return false;
        }
    }

    //captura de pie
    char destino = tablero[ff][cf];
    if (destino != '*') {
        if ((torre == 'T' && destino >= 'A' && destino <= 'Z') ||
            (torre == 't' && destino >= 'a' && destino <= 'z')) {
            return false;
        }
    }

    tablero[ff][cf] = torre;
    tablero[fi][ci] = '*';
    return true;
}
