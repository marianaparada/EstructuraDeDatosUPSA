#include <iostream>
#include "Stack.h"
using namespace std;
class Examen{

    private:
    int nota;
    public:
    Examen (){}
    Examen(int nota)
    : nota(nota){}
    int getNota() const {
        return nota;
    }
    friend ostream& operator<<(ostream &os, const Examen &e) {
    os << "[Nota del examen: " << e.nota<<"]";
    return os;
}
};
class Hojas{
    private:
    Stack<Examen> Pila;
    public:
    void Recibir (int n){
       int nota;

        for(int i=0; i<n; i++){

        cout<<"Nota ingresada: "<<i+1<<".-"<<endl;

        cin>>nota;
        if(nota>0&&nota<=100){
            Examen temp(nota);
            Pila.push(temp);
            cout<<endl;
            cout<<"Nota ingresada: "<<temp<<endl;
        }
        else{
            i--;
        }
        }
    }
    void Registrar (){
        Examen examen;
        float suma=0;
        int cont=0;
        while(Pila.pop(examen)){
            suma+= examen.getNota();
            cont ++;
            cout<<examen<<" fue registrada exitosamente."<<endl;
        }
        if(cont>0){
            float prom;
            prom=suma/cont;
            cout<<"El promedio de notas es: "<<prom<<endl;
        }
        else{
            cout<<"No hay notas que registrar"<<endl;
        }

    }
};
int main(){
    Hojas hojanotas;
    int n;
    cout<<"Ingrese la cantidad de examenes";
    cout<<endl;
    cin>>n;
    cout<<endl;
    hojanotas.Recibir(n);
    hojanotas.Registrar();
    return 0;
}
