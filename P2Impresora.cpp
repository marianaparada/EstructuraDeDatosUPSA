#include <iostream>
#include "Queue.h"
using namespace std;
class Trabajo {
    public:
    int n;
    string archivo;
    Trabajo(){}
    Trabajo(int n, const string &archivo) : n(n), archivo(archivo) {}

    friend ostream& operator<<(ostream &os, const Trabajo &t) {
        os << "[Numero de paginas: " << t.n << ", Nombre del archivo: " << t.archivo << "]";
        return os;
    }
};
class Impresora {
    private:
    Queue <Trabajo> orden;
    public:
    void Recibir(int n, const string &archivo){
        Trabajo nuevo(n,archivo);
        orden.push(nuevo);
        cout<<"Trabajo ingresado: "<<nuevo<<endl;
    }
    void Imprimir(){
        Trabajo actual;
        if(orden.pop(actual)){
           cout<<actual<<" fue impreso."<<endl;
        }
        else{
             cout<<"No hay trabajos en cola."<<endl;
        }
    }
    void Mostrar(){
        cout<<"Cola actual: "<<endl;
        orden.print();
    }
};
int main(){
    Impresora cola;
    cola.Recibir(9,"Trabajo 1");
    cola.Recibir(12, "Trabajo 2");
    cola.Recibir(3, "Trabajo 3");
    cola.Mostrar();
    cola.Imprimir();
    cola.Imprimir();
    cola.Mostrar();
    return 0;
}
