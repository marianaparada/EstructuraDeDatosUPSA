#include <iostream>
#include "Queue.h"
using namespace std;
class Paciente {
    private:
    int edad;
    string nombre,motivo;
    public:
    Paciente(){}
    Paciente(const string &nombre, int edad, const string &motivo)
    : nombre(nombre), edad(edad), motivo(motivo) {}

    friend ostream& operator<<(ostream &os, const Paciente &p) {
        os << "[Nombre: " << p.nombre << ", Edad: " << p.edad << ", Motivo:" << p.motivo<<"]";
        return os;
    }
};
class Clinica {
    private:
    Queue <Paciente> SalaEspera;
    public:
    void Recibir(const string &nombre, int edad, const string &motivo){
        Paciente nuevo(nombre,edad,motivo);
        SalaEspera.push(nuevo);
        cout<<"Ingreso el/la paciente: "<<nuevo<<endl;
    }
    void Salida(){
        Paciente actual;
        if(SalaEspera.pop(actual)){
           cout<<actual<<" ingreso a consulta."<<endl;
        }
        else{
             cout<<"No hay pacientes esperando."<<endl;
        }
    }
    void Mostrar(){
        cout<<"Pacientes en espera: "<<endl;
        SalaEspera.print();
    }
};
int main(){
    Clinica sala;
    sala.Recibir("Marisol",14,"Dolor de cabeza cronico.");
    sala.Recibir("Lidia",42, "Chequeo general.");
    sala.Recibir("Filomeno", 73, "Seguimiento post-cirugia.");
    sala.Recibir("Mario",24, "Chequeo general.");
    sala.Mostrar();
    sala.Salida();
    sala.Salida();
    sala.Mostrar();
    return 0;
}
