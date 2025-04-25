#include <iostream>
#include "Stack.h"
using namespace std;
class Accion{

    private:
    string tipo, cntnd;
    public:
    Accion (){}
    Accion(const string &tipo, const string &cntnd)
    : tipo(tipo), cntnd(cntnd){}
    friend ostream& operator<<(ostream &os, const Accion &a) {
    os << "[Tipo de accion: " << a.tipo<< ", Contenido de la operacion: " << a.cntnd <<"]";
    return os;
}
};
class Editor{
    private:
    Stack<Accion> lista;
    public:
    void Hacer (const string &tipo, const string &cntnd){
        Accion temp(tipo, cntnd);
        lista.push(temp);
        cout<<"Accion realizada: "<<temp<<endl;
    }
    void Deshacer (){
        Accion accion;
        if(lista.pop(accion)){
            cout<<"Se deshizo "<<accion;
        }

    }
    void Mostrar(){
        cout<<"Lista de acciones: "<<endl;
        lista.print();

    }
};
int main(){
    Editor pila;
    pila.Hacer("Copiar","Mi mama me mima");
    pila.Hacer("Borrar", "Mi mama me mima");
    pila.Hacer("Escribir","Mi mama no me mima");
    pila.Mostrar();
    pila.Deshacer();
    pila.Deshacer();
    cout<<endl;
    pila.Mostrar();
    return 0;
}

