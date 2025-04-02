//Operaciones entre Vectores: Crea la clase VectorCalculator que tenga métodos
//que reciban dos vectores como parámetros y calcule las siguientes operaciones
//elemento a elemento:
//- Suma
//- Resta
//- Multiplicación
#include <iostream>
#include "Vector.h"
using namespace std;
class VectorCalculator : public Vector<int>{
    public:
    static Vector<int> Suma(const Vector<int>&v1, const Vector<int>&v2){
        Vector<int>RS;
        int i, size=min(v1.getSize(),v2.getSize());
        for(i=0;i<size;i++){
            RS.pushBack(v1.at(i)+v2.at(i));
        }
        return RS;
    }
    static Vector<int> Resta(const Vector<int>&v1, const Vector<int>&v2){
        Vector<int>RR;
        int i, size=min(v1.getSize(),v2.getSize());
        for(i=0;i<size;i++){
            RR.pushBack(v1.at(i)-v2.at(i));
        }
        return RR;
    }
    static Vector<int> Producto(const Vector<int>&v1, const Vector<int>&v2){
        Vector<int>RP;
        int i, size=min(v1.getSize(),v2.getSize());
        for(i=0;i<size;i++){
            RP.pushBack(v1.at(i)*v2.at(i));
        }
        return RP;
    }
};
int main(){
    int i;
    Vector <int>v1,v2;
    v1.pushBack(9);
    v1.pushBack(0);
    v1.pushBack(2);
    v1.pushBack(1);

    v2.pushBack(4);
    v2.pushBack(5);
    v2.pushBack(4);
    v2.pushBack(8);
Vector<int>suma = VectorCalculator::Suma(v1,v2);
Vector<int>resta = VectorCalculator::Resta(v1,v2);
Vector<int>producto = VectorCalculator::Producto(v1,v2);

cout<<"El resultado de la suma entre vectores es: ";
for(i=0;i<suma.getSize();i++){
    cout<<suma.at(i)<<" ";
}
cout<<endl;
cout<<"El resultado de la resta entre vectores es: ";
for(i=0;i<resta.getSize();i++){
    cout<<resta.at(i)<<" ";
}
cout<<endl;
cout<<"El resultado del producto entre vectores es: ";
for(i=0;i<producto.getSize();i++){
    cout<<producto.at(i)<<" ";
}
cout<<endl;
return 0;
}
