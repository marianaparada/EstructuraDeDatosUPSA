//Inventario de Productos: Crea la clase Inventario, que gestione un vector de
//objetos de la clase Producto con los atributos:
//- id (numerico)
//- nombre
//- precio
//- cantidad en stock
//El sistema debe permitir:
//- Agregar y eliminar productos
//- Buscar productos por nombre.
//- Ordenar el inventario por precio
#include <iostream>
#include "Vector.h"
using namespace std;
class Producto {
    private:
    int id;
    string nombre;
    float precio;
    int stock;
    public:
    Producto (){
        id= 0;
        nombre= "desconocido";
        precio= 0.00;
        stock= 0;
    }
    Producto (int _id, string _nombre, float _precio, int _stock){
        id= _id;
        nombre= _nombre;
        precio= _precio;
        stock = _stock;
    }
    void setId(int _id){
        id= _id;
    }
    int getId(){
        return id;
    }
    void setNombre(string _nombre){
        nombre= _nombre;
    }
    string getNombre(){
        return nombre;
    }
    void setPrecio(float _precio){
        precio= _precio;
    }
    float getPrecio(){
        return precio;
    }
    void setStock(int _stock){
        stock= _stock;
    }
    int getStock(){
        return stock;
    }
    void mostrarProducto(){
        cout<<"Id: "<<getId()<<endl;
        cout<<"Nombre: "<<getNombre()<<endl;
        cout<<"Precio: $"<<getPrecio()<<endl;
        cout<<"Cantidad en stock: "<<getStock()<<endl;
    }
};
class Inventario{
    private:
    Vector<Producto>productos;
    public:
    void Agregar( Producto p){
        productos.pushBack(p);
    }
    void Eliminar (int id){
        Vector <Producto>k;
        int i;
        for (i=0;i<productos.getSize();i++){
            if(productos.at(i).getId()!=id){
                k.pushBack(productos.at(i));
                }
        }
            productos = Vector <Producto>();
            for (i=0;i<k.getSize();i++){
                productos.pushBack(k.at(i));
            }
    }
    Producto buscarNombre( string _nombre){
        int i;
        for(i=0;i<productos.getSize();i++){
            if(productos.at(i).getNombre()== _nombre){
            return productos.at(i);
            }
        }
        return Producto();
    }
    void Ordenar(){
        int i,j,k;
        for(i=0;i<productos.getSize()-1;i++){
            for(j=0;j<productos.getSize()-i-1;j++){
                if(productos.at(j).getPrecio()>productos.at(j+1).getPrecio()){
                    Producto k= productos.at(j);
                    productos.set(j, productos.at(j+1));
                    productos.set(j+1,k);
                }
            }
        }
    }
    void mostrarInventario (){
        int i;
        for(i=0;i<productos.getSize();i++){
            productos.at(i).mostrarProducto();
        }
    }
};
int main(){
    Inventario inv;
    inv.Agregar(Producto(101,"sarten",88.90,7));
    inv.Agregar(Producto(102,"olla inox 19'",165.00,4));
    inv.Agregar(Producto(103,"set 4 cuchillos",44.53,2));
    inv.Agregar(Producto(104,"batidora electrica",221.87,11));
    cout<<"Inventario: "<<endl;
    inv.mostrarInventario();
    cout<<endl;
    cout<<"Buscar set 4 cuchillos: "<<endl;
    Producto p=inv.buscarNombre("set 4 cuchillos");
    if(p.getId()!=0){
        p.mostrarProducto();
    }
    else{
        cout<<"El producto no se encuentra en el inventario."<<endl;
    }
    cout<<"Inventario ordenado por precio: "<<endl;
    inv.Ordenar();
    inv.mostrarInventario();
    cout<<endl;
    cout<<"Eliminar olla inox 19': "<<endl;
    inv.Eliminar(102);
    inv.mostrarInventario();
    return 0;
}

