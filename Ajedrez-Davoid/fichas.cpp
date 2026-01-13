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

            // Promocion a reina
            if (ff == 0) tablero[ff][cf] = 'Q';

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

        // Captura
        if (ff == fi - 1 && (cf == ci - 1 || cf == ci + 1) &&
            tablero[ff][cf] >= 'a' && tablero[ff][cf] <= 'z') {

            tablero[ff][cf] = 'P';
            tablero[fi][ci] = '*';

            // Promocion a reina
            if (ff == 0) tablero[ff][cf] = 'Q';

            return true;
        }
    }

    // peon negro
    if (peon == 'p' && turno % 2 != 0) {

        // Movimiento normal
        if (ff == fi + 1 && cf == ci && tablero[ff][cf] == '*') {
            tablero[ff][cf] = 'p';
            tablero[fi][ci] = '*';

            // Promocion a reina
            if (ff == N - 1) tablero[ff][cf] = 'q';

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

        // Captura
        if (ff == fi + 1 && (cf == ci - 1 || cf == ci + 1) &&
            tablero[ff][cf] >= 'A' && tablero[ff][cf] <= 'Z') {

            tablero[ff][cf] = 'p';
            tablero[fi][ci] = '*';

            // Promocion a reina
            if (ff == N - 1) tablero[ff][cf] = 'q';

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

    //Captura de ficha
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
        //captura de caballo
        char destino = tablero[ff][cf];
        if (destino != '*') {
            if ((caballo == 'H' && destino >= 'A' && destino <= 'Z') ||
                (caballo == 'h' && destino >= 'a' && destino <= 'z')) {
                return false;
            }
        }
        tablero[ff][cf] = caballo;
        tablero[fi][ci] = '*';
        return true;
    }
    return false;
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
    //Captura de ficha
    char destino = tablero[ff][cf];
    if (destino != '*') {
        if ((alfil == 'B' && destino >= 'A' && destino <= 'Z') ||
            (alfil == 'b' && destino >= 'a' && destino <= 'z')) {
            return false;
        }
    }

    // Camino libre
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
    // Camino libre
    else if (abs(ff - fi) == abs(cf - ci)) {
        int movimientoFila = (ff > fi) ? 1 : -1;
        int movimientoCol = (cf > ci) ? 1 : -1;
        int pasos = abs(ff - fi);
        for (int i = 1; i < pasos; ++i) {
            if (tablero[fi + i * movimientoFila][ci + i * movimientoCol] != '*') return false;
        }
    }

    // Captura de ficha
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

    // Captura de ficha
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


// (idea referenciada de chatgpt)
bool enJaque(char tablero[N][N], bool blancas) {

    int filar = -1, columnar = -1;
    char rey = blancas ? 'K' : 'k';

    // Buscamos la posicion del rei en el tablero
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] == rey) {
                filar = i;
                columnar = j;
                break;
            }
        }
    }

    if (filar == -1) return false;

    // Pieza creando el jaque
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            char pieza = tablero[i][j];
            if (pieza == '*') continue;

            // Ignorar piezas aliadas
            if (blancas && pieza >= 'A' && pieza <= 'Z') continue;
            if (!blancas && pieza >= 'a' && pieza <= 'z') continue;

            int df = filar - i;
            int dc = columnar - j;

            // Peon
            if (pieza == 'p' && blancas) {
                if (df == 1 && (dc == 1 || dc == -1)) return true;
            }
            if (pieza == 'P' && !blancas) {
                if (df == -1 && (dc == 1 || dc == -1)) return true;
            }

            // Caballo (ayuda con chatgpt)
            if (pieza == 'h' || pieza == 'H') {
                if ((abs(df) == 2 && abs(dc) == 1) || (abs(df) == 1 && abs(dc) == 2)) return true;
            }

            // Torre o Reina (horizontal/vertical)
            if (pieza == 't' || pieza == 'T' || pieza == 'q' || pieza == 'Q') {
                if (df == 0 || dc == 0) {
                    int fila_ataque = (df == 0) ? 0 : (df > 0 ? 1 : -1);
                    int columna_ataque = (dc == 0) ? 0 : (dc > 0 ? 1 : -1);
                    int f = i + fila_ataque, c = j + columna_ataque;
                    while (f != filar || c != columnar) {
                        if (tablero[f][c] != '*') break;
                        f += fila_ataque;
                        c += columna_ataque;
                    }
                    if (f == filar && c == columnar) return true;
                }
            }

            // Alfil o Reina (diagonal)
            if (pieza == 'b' || pieza == 'B' || pieza == 'q' || pieza == 'Q') {
                if (abs(df) == abs(dc)) {
                    int fila_ataque = df > 0 ? 1 : -1;
                    int columna_ataque = dc > 0 ? 1 : -1;
                    int f = i + fila_ataque, c = j + columna_ataque;
                    while (f != filar && c != columnar) {
                        if (tablero[f][c] != '*') break;
                        f += fila_ataque;
                        c += columna_ataque;
                    }
                    if (f == filar && c == columnar) return true;
                }
            }
        }
    }
    return false;
}

