//Cálculos Estadísticos sobre Vectores: Crea la clase MathVector, que derive de
//Vector<int>, e implemente métodos para:
//- Calcular el promedio de los valores del vector.
//- Determinar la mediana del conjunto de datos.
//- Identificar la moda (el número que más veces aparece).
#include <iostream>
#include "Vector.h"
using namespace std;
class MathVector : public Vector<int>{
    private:
    float promedio;
    float mediana;
    float moda;
    public:
    MathVector (): promedio(0), mediana(0), moda(0){}

    void calcularPromedio (float& _promedio){
        int suma=0, i;
        for (i=0; i<getSize();i++){
            suma += at(i);
        }
        _promedio = static_cast<float>(suma)/getSize();
        promedio= _promedio;
    }
    void setPromedio (float _promedio){
        promedio = _promedio;
    }
    float getPromedio (){
        return promedio;
    }
    void calcularMediana (float& _mediana){
        int i, j, k, m;
        for(i=0; i<getSize()-1;i++){
            for (j=i+1;j<getSize();j++){
                if(at(j)<at(i)){
                    k=at(i);
                    set(i,at(j));
                    set(j,k);
                }
            }
        }
        m=getSize()/2;
        if(getSize()%2==0){
            _mediana=(at(m-1)+at(m))/ 2.0 ;
        }
        else{
            _mediana=at(m);
        }
        mediana=_mediana;
    }
    void setMediana (float _mediana){
        mediana= _mediana;
    }
    float getMediana(){
        return mediana;
    }
    void calcularModa(float& _moda){
        int max=0,i,j,f=0;
        _moda=at(0);
        for(i=0;i<getSize(); i++){
            f=0;
            for(j=0; j<getSize();j++){
                if(at(j)==at(i)){
                    f++;
                }
            }
            if (f>max){
                max=f;
            _moda = at(i);
            }
        }
        moda= _moda;
    }
    void setModa (float _moda){
        moda = _moda;
    }
    float getModa(){
        return moda;
    }
};
int main(){
    MathVector v;
    v.pushBack(8);
    v.pushBack(0);
    v.pushBack(3);
    v.pushBack(11);
    v.pushBack(2);
    v.pushBack(7);
    v.pushBack(7);
    float _promedio, _mediana, _moda;
    v.calcularPromedio(_promedio);
    v.calcularMediana(_mediana);
    v.calcularModa(_moda);
    cout<<"El promedio del vector es: "<<v.getPromedio()<<endl;
    cout<<"La mediana del vector es: "<<v.getMediana()<<endl;
    cout<<"La moda del vector es: "<<v.getModa()<<endl;
    return 0;
}
