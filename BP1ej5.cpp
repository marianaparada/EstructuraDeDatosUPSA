//Operaciones entre Matrices: Crea la clase MatrixCalculator, que implemente
//métodos para realizar operaciones entre matrices del mismo tamaño:
//- Suma
//- Resta
//- Multiplicación
#include <iostream>
#include <stdexcept>
#include "Matrix.h"
using namespace std;

template <int ROWS, int COLS>
class MatrixCalculator : public Matrix<int, ROWS, COLS>
{
  public:
    Matrix<int, ROWS, COLS> suma(const Matrix<int, ROWS, COLS>& otraMatriz) const
    {
        Matrix<int, ROWS, COLS> resultado;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                resultado.set(i, j, this->at(i, j) + otraMatriz.at(i, j));
            }
        }
        return resultado;
    }

    Matrix<int, ROWS, COLS> resta(const Matrix<int, ROWS, COLS>& otraMatriz) const
    {
        Matrix<int, ROWS, COLS> resultado;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                resultado.set(i, j, this->at(i, j) - otraMatriz.at(i, j));
            }
        }
        return resultado;
    }

    Matrix<int, ROWS, COLS> producto(const Matrix<int, ROWS, COLS>& otraMatriz) const
    {
        Matrix<int, ROWS, COLS> resultado;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                int suma = 0;
                for (int k = 0; k < COLS; k++)
                {
                    suma += this->at(i, k) * otraMatriz.at(k, j);
                }
                resultado.set(i, j, suma);
            }
        }
        return resultado;
    }
};

int main()
{
    MatrixCalculator<4, 4> matriz1;
    MatrixCalculator<4, 4> matriz2;

    int valor = 1;
    for (int i = 0; i < matriz1.numRows(); i++)
    {
        for (int j = 0; j < matriz1.numCols(); j++)
        {
            matriz1.set(i, j, valor++);
        }
    }

    valor = 22;
    for (int i = 0; i < matriz2.numRows(); i++)
    {
        for (int j = 0; j < matriz2.numCols(); j++)
        {
            matriz2.set(i, j, valor--);
        }
    }

    cout << "Matriz 1:" << endl;
    matriz1.print();

    cout << "Matriz 2:" << endl;
    matriz2.print();

    Matrix<int, 4, 4> sumaMatriz = matriz1.suma(matriz2);
    cout << "Suma:" << endl;
    sumaMatriz.print();

    Matrix<int, 4, 4> restaMatriz = matriz1.resta(matriz2);
    cout << "Resta:" << endl;
    restaMatriz.print();

    Matrix<int, 4, 4> productoMatriz = matriz1.producto(matriz2);
    cout << "Producto:" << endl;
    productoMatriz.print();

    return 0;
}
