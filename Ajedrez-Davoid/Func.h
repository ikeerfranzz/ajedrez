#pragma once
#define N 8

extern int turno;

void creartablero(char tablero[N][N]);
bool moverPeon(char tablero[N][N], int fi, int ci, int ff, int cf);
bool moverTorre(char tablero[N][N], int fi, int ci, int ff, int cf);
bool moverCaballo(char tablero[N][N], int fi, int ci, int ff, int cf);
bool moverAlfil(char tablero[N][N], int fi, int ci, int ff, int cf);
