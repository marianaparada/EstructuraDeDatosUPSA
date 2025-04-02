//Simetría en una Matriz: Crea la clase MathMatrix que derive de Matrix<int, ROWS,
//COLS> y agrega un método que determine si una matriz cuadrada es simétrica:
//Simétrica               No simétrica
//  1 2 3                     1 4 7
//  2 5 6                     2 5 8
//  3 6 9                     3 6 9

#include "Matrix.h"
#include <iostream>
using namespace std;

template <int ROWS, int COLS>
class MathMatrix : public Matrix<int, ROWS, COLS> {
public:
    // Método para verificar si la matriz es simétrica
    bool esSimetrica() {
        if (ROWS != COLS) {
            // Si no es cuadrada, no puede ser simétrica
            return false;
        }

        // Compara los elementos en la posición (i, j) con (j, i)
        for (int i = 0; i < ROWS; i++) {
            for (int j = i; j < COLS; j++) {  // Solo necesitamos verificar la mitad superior
                if (this->m[i][j] != this->m[j][i]) {
                    return false;  // No es simétrica
                }
            }
        }
        return true;  // Es simétrica
    }
};

int main() {
    MathMatrix<3, 3> m;
    int value = 1;

    // Rellenar la matriz con valores consecutivos
    for (int i = 0; i < m.numRows(); i++) {
        for (int j = 0; j < m.numCols(); j++) {
            m.set(i, j, value++);
        }
    }

    // Mostrar la matriz
    cout << "La matriz es: " << endl;
    m.print();
    cout << endl;

    // Verificar si la matriz es simétrica
    cout << "¿Es simétrica? " << (m.esSimetrica() ? "Sí" : "No") << endl;

    return 0;
}
