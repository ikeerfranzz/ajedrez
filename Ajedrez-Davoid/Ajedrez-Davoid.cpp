#include <iostream>

int main() {
    const int N = 8;

    // Numeros superiores
    std::cout << "  ";
    for (int i = 1; i <= N; i++) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // Letras del tablero
    char tablero[N][N] = {
        {'t','h','b','k','q','b','h','t'},
        {'p','p','p','p','p','p','p','p'},
        {'*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*'},
        {'P','P','P','P','P','P','P','P'},
        {'T','H','B','Q','K','B','H','T'}
    };

    // Imprimir filas con numeros izquierda
    for (int i = 0; i < N; i++) {
        std::cout << (N - i) << ' ';
        for (int j = 0; j < N; j++) {
            std::cout << tablero[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
