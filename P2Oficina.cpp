#include <iostream>
#include "Stack.h"
using namespace std;
class Doc{

    private:
    string titulo, fecha;
    public:
    Doc (){}
    Doc(const string &titulo, const string &fecha)
    :  titulo(titulo), fecha(fecha){}
    friend ostream& operator<<(ostream &os, const Doc &d) {
    os << "[Titulo del documento: " << d.titulo <<", Fecha de entrega: "<< d.fecha<<"]";
    return os;
}
};
class Pila{
    private:
    Stack<Doc> vieja;
    Stack<Doc> nueva;
    public:
    void Recibir (const string &titulo, const string &fecha){
        Doc temp(titulo, fecha);
        vieja.push(temp);
        cout<<"Libro ingresado: "<<temp<<endl;
    }
    void Registrar (){
        Doc doc;
        if(vieja.pop(doc)){
            nueva.push(doc);
            cout<<doc<<" fue registrado exitosamente.";
        }

    }
    void Mostrar(){
        cout<<"Documentos en revision: "<<endl;
        vieja.print();
        cout<<"Documentos revisados: "<<endl;
        nueva.print();
    }
};
int main(){
    Pila pila;
    pila.Recibir("Contrato 3","02/04/25");
    pila.Recibir("Contrato 6", "02/04/2025");
    pila.Recibir("Informe tecnico A33", "13/04/2025");
    pila.Mostrar();
    pila.Registrar();
    pila.Registrar();
    pila.Registrar();
    cout<<endl;
    pila.Mostrar();
    return 0;
}


