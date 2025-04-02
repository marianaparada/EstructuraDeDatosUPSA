//Suma de Elementos Impares en una Matriz: Implementa una función que reciba
//una matriz de enteros y retorne la suma de todos los números impares contenidos en ella.
#include <iostream>
#include "Matrix.h"
using namespace std;

template < int ROWS, int COLS>
int sumaImpar(const Matrix<int, ROWS, COLS>& matriz) {
    int suma = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int valor = matriz.at(i, j);
            if (valor % 2 != 0) {
                suma += valor;
            }
        }
    }
    return suma;
}

int main() {
    Matrix<int, 4, 4> mat;
    int valores[4][4] = {
        {1, 2, 3, 4},
        {3, 4, 2, 1},
        {9, 2, 3, 2},
        {1, 2, 1, 3}
    };
    for (int i = 0; i < mat.numRows(); i++) {
        for (int j = 0; j < mat.numCols(); j++) {
            mat.set(i, j, valores[i][j]);
        }
    }
    cout << "La matriz original es: " << endl;
    mat.print();
    cout << endl;
    cout << "La suma de valores impares de la matriz es: " << sumaImpar(mat) << endl;

    return 0;
}
