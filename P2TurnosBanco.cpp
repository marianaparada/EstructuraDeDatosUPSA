#include <iostream>
#include "Queue.h"
using namespace std;
class Cliente {
    private:
    string nombre,motivo;
    public:
    Cliente(){}
    Cliente(const string &nombre, const string &motivo)
    : nombre(nombre), motivo(motivo) {}

    friend ostream& operator<<(ostream &os, const Cliente &c) {
        os << "[Nombre: " << c.nombre << ", Motivo:" << c.motivo<<"]";
        return os;
    }
};
class Banco {
    private:
    Queue <Cliente> Fila;
    public:
    void Entrada(const string &nombre, const string &motivo){
        Cliente nuevo(nombre,motivo);
        Fila.push(nuevo);
        cout<<"Ingreso el/la cliente/a: "<<nuevo<<endl;
    }
    void Salida(){
        Cliente actual;
        if(Fila.pop(actual)){
           cout<<actual<<" ingreso a kiosko."<<endl;
        }
        else{
             cout<<"No hay clientes esperando."<<endl;
        }
    }
    void Mostrar(){
        cout<<"Clientes en espera: "<<endl;
        Fila.print();
    }
};
int main(){
    Banco fila;
    fila.Entrada("Lisa","Deposito.");
    fila.Entrada("Marcelo", "Retiro.");
    fila.Entrada("Ana", "Retiro.");
    fila.Entrada("Flavio", "Deposito.");
    fila.Mostrar();
    fila.Salida();
    fila.Salida();
    fila.Mostrar();
    return 0;
}
