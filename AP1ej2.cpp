//Suma de Pares en Vectores: Implementa una función que calcule la suma de los
//números pares en un vector de enteros.
#include <iostream>
#include "Vector.h"
using namespace std;
int SumaPar (const Vector<int> &v){
    int i=0, suma=0;
    bool Impar=false;

    for (i=0; i<v.getSize(); i++){
        if(v.at(i)%2==0){
            suma+= v.at(i);
        }
        else{
            cout<<v.at(i)<<" ";
            Impar=true;
        }
    }
        if(Impar==false){
            cout<<"No hay numeros impares en el vector.";
        }
        else{
            cout<<"Los valores impares que no se suman son: ";
        }
    cout<<endl;
    return suma;
}
int main(){
    int i=0, R;
    Vector<int>v;
    v.pushBack(2);
    v.pushBack(2);
    v.pushBack(8);
    cout<<"Del vector: "<<endl;
    v.print();
    R=SumaPar(v);
    cout<<"La suma de los numeros pares del vector es: "<<R<<endl;
    return 0;
}
