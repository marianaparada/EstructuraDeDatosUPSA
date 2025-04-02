//Máximo y Mínimo: Añade a la clase MathVector los siguientes métodos:
//- Encontrar el valor máximo del vector.
//- Encontrar el valor mínimo del vector
#include <iostream>
#include "Vector.h"
using namespace std;
class MathVector : public Vector<int>{
    private:
    int maximo;
    int minimo;
    public:
    MathVector (): maximo(0), minimo(0) {}

    void Maximo (float& _maximo){
        int i;
        _maximo =at(0);
        for(i=1;i<getSize();i++){
                if(at(i)>_maximo){
                    _maximo =at(i);
                }
            }
        maximo= _maximo;
    }
    void setMaximo (float _maximo){
        maximo= _maximo;
    }
    float getMaximo (){
        return maximo;
    }
    void Minimo (float& _minimo){
        int i;
        _minimo =at(0);
        for(i=1;i<getSize();i++){
                if(at(i)<_minimo){
                    _minimo =at(i);
                }
        }
        minimo= _minimo;
    }
    void setMinimo (float _minimo){
        minimo=_minimo;
    }
    float getMinimo (){
        return minimo;
    }
};
int main(){
    MathVector v;
    v.pushBack(3);
    v.pushBack(8);
    v.pushBack(4);
    v.pushBack(10);
    float _maximo, _minimo;
    v.Maximo(_maximo);
    v.Minimo(_minimo);
cout<<"El valor maximo del vector es: "<<v.getMaximo()<<endl;
cout<<"El valor minimo del vector es: "<<v.getMinimo()<<endl;
return 0;
}
