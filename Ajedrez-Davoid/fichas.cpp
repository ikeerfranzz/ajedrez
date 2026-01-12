#include "Func.h"
#include <math.h>

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

bool moverCaballo(char tablero[N][N], int fi, int ci, int ff, int cf) {
    char caballo = tablero[fi][ci];

    // Turno correcto
    if ((caballo == 'H' && turno % 2 != 0) ||
        (caballo == 'h' && turno % 2 == 0)) {
        return false;
    }


    if (ff == fi - 2 && cf == ci + 1 ||
        ff == fi - 2 && cf == ci - 1 ||
        ff == fi - 1 && cf == ci + 2 ||
        ff == fi + 1 && cf == ci + 2 ||
        ff == fi - 1 && cf == ci - 2 ||
        ff == fi + 1 && cf == ci - 2 ||
        ff == fi + 2 && cf == ci - 1 ||
        ff == fi + 2 && cf == ci + 1
        )
    {
        //captura de pie
        char destino = tablero[ff][cf];
        if (destino != '*') {
            if ((caballo == 'H' && destino >= 'A' && destino <= 'Z') ||
                (caballo == 'h' && destino >= 'a' && destino <= 'z')) {
                return false;
            }
        }
        tablero[ff][cf] = 'H';
        tablero[fi][ci] = '*';
        return true;
    }
    return true;
}

bool moverAlfil(char tablero[N][N], int fi, int ci, int ff, int cf) {
    if (fi == ff && ci == cf) return false;

    char alfil = tablero[fi][ci];

    // Turno correcto
    if ((alfil == 'B' && turno % 2 != 0) ||
        (alfil == 'b' && turno % 2 == 0)) {
        return false;
    }

    // Solo diagonales
    if (abs(ff - fi) != abs(cf - ci)) {
        return false;
    }
    //pieza destino valida
    char destino = tablero[ff][cf];
    if (destino != '*') {
        if ((alfil == 'B' && destino >= 'A' && destino <= 'Z') ||
            (alfil == 'b' && destino >= 'a' && destino <= 'z')) {
            return false;
        }
    }

    //camino libre
    int movimientoFila = (ff > fi) ? 1 : -1;
    int movimientoCol = (cf > ci) ? 1 : -1;
    int pasos = abs(ff - fi);
    for (int i = 1; i < pasos; ++i) {
        if (tablero[fi + i * movimientoFila][ci + i * movimientoCol] != '*') return false;
    }

    tablero[ff][cf] = alfil;
    tablero[fi][ci] = '*';

    return true;
}

bool moverReina(char tablero[N][N], int fi, int ci, int ff, int cf) {
    if (fi == ff && ci == cf) return false;

    char reina = tablero[fi][ci];

    // Turno correcto
    if ((reina == 'Q' && turno % 2 != 0) ||
        (reina == 'q' && turno % 2 == 0)) {
        return false;
    }

    // Movimiento tipo torre
    if (fi == ff || ci == cf) {

        // Movimiento vertical
        if (ci == cf) {
            int paso = (ff > fi) ? 1 : -1;
            for (int i = fi + paso; i != ff; i += paso) {
                if (tablero[i][ci] != '*') return false;
            }
        }

        // Movimiento horizontal
        if (fi == ff) {
            int paso = (cf > ci) ? 1 : -1;
            for (int j = ci + paso; j != cf; j += paso) {
                if (tablero[fi][j] != '*') return false;
            }
        }
    }
    //camino libre
    else if (abs(ff - fi) != abs(cf - ci)) {
        int movimientoFila = (ff > fi) ? 1 : -1;
        int movimientoCol = (cf > ci) ? 1 : -1;
        int pasos = abs(ff - fi);
        for (int i = 1; i < pasos; ++i) {
            if (tablero[fi + i * movimientoFila][ci + i * movimientoCol] != '*') return false;
        }
    }

    // Pieza destino válida
    char destino = tablero[ff][cf];
    if (destino != '*') {
        if ((reina == 'Q' && destino >= 'A' && destino <= 'Z') ||
            (reina == 'q' && destino >= 'a' && destino <= 'z')) {
            return false;
        }
    }

    tablero[ff][cf] = reina;
    tablero[fi][ci] = '*';
    return true;
}



bool moverRei(char tablero[N][N], int fi, int ci, int ff, int cf) {
    char rei = tablero[fi][ci];

    // No moverse al mismo sitio
    if (fi == ff && ci == cf) return false;

    // Turno correcto
    if ((rei == 'K' && turno % 2 != 0) ||
        (rei == 'k' && turno % 2 == 0)) {
        return false;
    }

    // Solo 1 casilla en cualquier dirección
    if (abs(ff - fi) > 1 || abs(cf - ci) > 1) {
        return false;
    }

    // Pieza destino válida
    char destino = tablero[ff][cf];
    if (destino != '*') {
        if ((rei == 'K' && destino >= 'A' && destino <= 'Z') ||
            (rei == 'k' && destino >= 'a' && destino <= 'z')) {
            return false;
        }
    }

    tablero[ff][cf] = rei;
    tablero[fi][ci] = '*';
    return true;
}

