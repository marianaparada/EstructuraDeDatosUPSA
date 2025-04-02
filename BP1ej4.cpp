//Máximo, Mínimo y Promedio en una Matriz: Añade a MathMatrix métodos que
//encuentren el valor máximo, el valor mínimo y el promedio de una matriz.

#include "Matrix.h"
#include <iostream>
using namespace std;

template <int ROWS, int COLS>
class MathMatrix : public Matrix<int, ROWS, COLS> {
public:
    // Método para encontrar el valor máximo en la matriz
    int MaxValor() {
        int max = this->m[0][0];  // Inicializa el valor máximo con el primer valor
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (this->m[i][j] > max) {
                    max = this->m[i][j];  // Actualiza el máximo
                }
            }
        }
        return max;
    }

    // Método para encontrar el valor mínimo en la matriz
    int MinValor() {
        int min = this->m[0][0];  // Inicializa el valor mínimo con el primer valor
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (this->m[i][j] < min) {
                    min = this->m[i][j];  // Actualiza el mínimo
                }
            }
        }
        return min;
    }

    // Método para calcular el promedio de los valores en la matriz
    float promedio() {
        int suma = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                suma += this->m[i][j];  // Suma todos los elementos
            }
        }
        return static_cast<float>(suma) / (ROWS * COLS);  // Promedio como float
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

    // Calcular y mostrar el valor máximo, mínimo y promedio
    cout << "El valor máximo es: " << m.MaxValor() << endl;
    cout << "El valor mínimo es: " << m.MinValor() << endl;
    cout << "El promedio es: " << m.promedio() << endl;

    return 0;
}
