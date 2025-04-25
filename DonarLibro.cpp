#include <iostream>
#include "Stack.h"
using namespace std;
class Libro{

    private:
    string autor, titulo, editorial;
    public:
    Libro (){}
    Libro(const string &autor, const string &titulo, const string &editorial)
    : autor(autor), titulo(titulo), editorial(editorial){}
    friend ostream& operator<<(ostream &os, const Libro &l) {
    os << "[Autor: " << l.autor<< ", Titulo: " << l.titulo <<", Editorial: "<< l.editorial<<"]";
    return os;
}
};
class Estante{
    private:
    Stack<Libro> PilaEstante;
    Stack<Libro> nueva;
    public:
    void Recibir (const string &autor, const string &titulo, const string &editorial){
        Libro temp(autor, titulo, editorial);
        PilaEstante.push(temp);
        cout<<"Libro ingresado: "<<temp<<endl;
    }
    void Registrar (){
        Libro libro;
        if(PilaEstante.pop(libro)){
            nueva.push(libro);
            cout<<libro<<" fue registrado exitosamente.";
        }

    }
    void Mostrar(){
        cout<<"Estanteria ingresos: "<<endl;
        PilaEstante.print();
        cout<<"Estanteria organizada: "<<endl;
        nueva.print();
    }
};
int main(){
    Estante estanteria;
    estanteria.Recibir("Homero","Odisea","ABCD");
    estanteria.Recibir("F. Scott Fitzgerald", "El Gran Gatsby", "Lalelilolu");
    estanteria.Recibir("Franz Kafka", "Metamorfosis", "La Hoguera");
    estanteria.Mostrar();
    estanteria.Registrar();
    cout<<endl;
    estanteria.Mostrar();
    return 0;
}


