#include <iostream>
#include "Stack.h"
using namespace std;
class Plato{

    private:
    string id;
    public:
    Plato (){}
    Plato(const string &id)
    : id(id){}
    friend ostream& operator<<(ostream &os, const Plato &p) {
    os << "[Identificador: " << p.id<< "]";
    return os;
}
};
class Pila{
    private:
    Stack<Plato> sucio;
    Stack<Plato> limpio;
    public:
    void Recibir (const string &id){
        Plato temp(id);
        sucio.push(temp);
        cout<<"Plato sucio: "<<temp<<endl;
    }
    void Lavar (){
        Plato plato;
        if(sucio.pop(plato)){
            limpio.push(plato);
            cout<<plato<<" fue lavado.";
        }
    }
    void Mostrar(){
        cout<<"Pila sucia: "<<endl;
        sucio.print();
        cout<<"Pila limpia: "<<endl;
        limpio.print();
    }
};
int main(){
    Pila pila;
    pila.Recibir("Hondo");
    pila.Recibir("Plano");
    pila.Recibir("Decorativo");
    pila.Recibir("Platillo");
    pila.Recibir("Platillo");
    pila.Mostrar();
    pila.Lavar();
    cout<<endl;
    pila.Lavar();
    cout<<endl;
    pila.Lavar();
    cout<<endl;
    pila.Lavar();
    cout<<endl;
    pila.Lavar();
    cout<<endl;
    pila.Mostrar();
    return 0;
}
