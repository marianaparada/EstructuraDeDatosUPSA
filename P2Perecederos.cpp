#include <iostream>
#include "Queue.h"
using namespace std;
class Caja {
    public:
    string fecha;
    int n;
    Caja(){}
    Caja(const string &fecha, int n) : fecha(fecha), n(n) {}

    friend ostream& operator<<(ostream &os, const Caja &c) {
        os << "[Fecha de vencimiento: " << c.fecha << ", cantidad de unidades: " << c.n << "]";
        return os;
    }
};
class Supermercado {
    private:
    Queue <Caja> almacen;
    public:
    void Recibir(const string &fecha, int n){
        Caja nuevo(fecha,n);
        almacen.push(nuevo);
        cout<<"Caja recibida: "<<nuevo<<endl;
    }
    void Salida(){
        Caja actual;
        if(almacen.pop(actual)){
           cout<<actual<<" fue colocado en la estanteria especial."<<endl;
        }
        else{
             cout<<"No hay cajas por retirar."<<endl;
        }
    }
    void Mostrar(){
        cout<<"Inventario en almacen: "<<endl;
        almacen.print();
    }
};
int main(){
    Supermercado estanteria;
    estanteria.Recibir("02/09/2024",8);
    estanteria.Recibir("12/09/2024", 9);
    estanteria.Recibir("31/12/2024", 4);
    estanteria.Recibir("14/01/2025", 23);
    estanteria.Mostrar();
    estanteria.Salida();
    estanteria.Salida();
    estanteria.Mostrar();
    return 0;
}
