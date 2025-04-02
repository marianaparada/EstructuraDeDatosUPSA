// Cálculo de la Suma de Cada Fila: Escribe una función que reciba una matriz de
//enteros y devuelva un vector con la suma de cada fila
#include <iostream>
#include "Matrix.h"
#include "Vector.h"
using namespace std;
template<typename T,int ROWS, int COLS>
Vector <T> sumaFilas (const Matrix<T, ROWS, COLS> &matriz){
    int i,j;
    Vector<T> resultado;
    for(i=0;i<ROWS;i++){
        T suma=0;
        for(j=0;j<COLS;j++){
            suma +=matriz.at(i,j);
        }
        resultado.pushBack(suma);
    }
    return resultado;
}
int main(){
    Matrix <int, 4,4>mat;
    int i,j;
    int valores[4][4]={
        {8,1,8,7},
        {2,4,5,2},
        {1,2,5,6},
        {0,2,6,3}};
        for (i=0;i<mat.numRows();i++){
            for(j=0;j<mat.numCols();j++){
                mat.set(i,j, valores[i][j]);
            }
        }
        cout<<"La matriz original es: "<<endl;
        mat.print();
        cout<<endl;
        Vector<int>sumafilas=sumaFilas(mat);
        cout<<"La suma de las filas es: "<<endl;
        sumafilas.print();
        cout<<endl;
        return 0;
    }
