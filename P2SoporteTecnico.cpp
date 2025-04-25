#include <iostream>
#include "Queue.h"
using namespace std;
class Cliente {
    public:
    string nombre, problema;
    Cliente(){}
    Cliente(const string &nombre, const string &problema) : nombre(nombre), problema(problema) {}

    friend ostream& operator<<(ostream &os, const Cliente &c) {
        os << "[Nombre: " << c.nombre << ", Descripcion del problema: " << c.problema << "]";
        return os;
    }
};
class Soporte {
    private:
    Queue <Cliente> cola;
    public:
    void Recibir(const string &nombre, const string &problema){
        Cliente nuevo(nombre,problema);
        cola.push(nuevo);
        cout<<nuevo<<" ingreso a la cola. "<<endl;
    }
    void Salida(){
        Cliente actual;
        if(cola.pop(actual)){
           cout<<actual<<" fue atendida/o."<<endl;
        }
        else{
             cout<<"No hay mas clientes por atender."<<endl;
        }
    }
    void Mostrar(){
        cout<<"Cola actual: "<<endl;
        cola.print();
    }
};
int main(){
    Soporte consulta;
    consulta.Recibir("Paula","No enciende mi dispositivo");
    consulta.Recibir("Alejandra", "Mi dispositivo no es compatible con su servicio");
    consulta.Recibir("Saul", "Mi dispositivo vino defectuoso");
    consulta.Mostrar();
    consulta.Salida();
    consulta.Salida();
    consulta.Mostrar();
    return 0;
}
