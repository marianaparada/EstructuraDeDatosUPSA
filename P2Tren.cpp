#include <iostream>
#include "Queue.h"
using namespace std;
class Pasajero {
    public:
    string nombre, destino;
    Pasajero(){}
    Pasajero(const string &nombre, const string &destino) : nombre(nombre), destino(destino) {}

    friend ostream& operator<<(ostream &os, const Pasajero &p) {
        os << "[Nombre: " << p.nombre << ", Destino: " << p.destino << "]";
        return os;
    }
};
class Tren {
    private:
    Queue <Pasajero> cola;
    public:
    void Recibir(const string &nombre, const string &destino){
        Pasajero nuevo(nombre,destino);
        cola.push(nuevo);
        cout<<"Cliente: "<<nuevo<<" ingreso a la cola"<<endl;
    }
    void Salida(){
        Pasajero actual;
        if(cola.pop(actual)){
           cout<<actual<<" obtuvo su boleto."<<endl;
        }
        else{
             cout<<"No hay mas pasajeros."<<endl;
        }
    }
    void Mostrar(){
        cout<<"Cola de pasajeros actual: "<<endl;
        cola.print();
    }
};
int main(){
    Tren boleto;
    boleto.Recibir("Laura","Pando");
    boleto.Recibir("Ignacio", "Paila");
    boleto.Recibir("Maria Jose", "Corumba");
    boleto.Recibir("Jose Maria", "Villa Tunari");
    boleto.Mostrar();
    boleto.Salida();
    boleto.Salida();
    boleto.Salida();
    boleto.Mostrar();
    return 0;
}
