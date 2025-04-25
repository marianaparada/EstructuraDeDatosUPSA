#include <iostream>
#include "Queue.h"
using namespace std;
class Paquete {
    public:
    int id;
    string tipo;
    Paquete(){}
    Paquete(int id, const string &tipo) : id(id), tipo(tipo) {}

    friend ostream& operator<<(ostream &os, const Paquete &p) {
        os << "[ID: " << p.id << ", Tipo: " << p.tipo << "]";
        return os;
    }
};
class Inventario {
    private:
    Queue <Paquete> almacen;
    public:
    void Recibir(int id, const string &tipo){
        Paquete nuevo(id,tipo);
        almacen.push(nuevo);
        cout<<"Paquete recibido: "<<nuevo<<endl;
    }
    void Salida(){
        Paquete actual;
        if(almacen.pop(actual)){
           cout<<actual<<" fue retirado del almacen."<<endl;
        }
        else{
             cout<<"No hay paquetes por retirar."<<endl;
        }
    }
    void Mostrar(){
        cout<<"Inventario actual: "<<endl;
        almacen.print();
    }
};
int main(){
    Inventario tienda;
    tienda.Recibir(1,"Camisa azul");
    tienda.Recibir(2, "Pantalon verde");
    tienda.Recibir(3, "Camisa roja");
    tienda.Recibir(4, "Vestido naranja");
    tienda.Mostrar();
    tienda.Salida();
    tienda.Salida();
    tienda.Mostrar();
    return 0;
}
