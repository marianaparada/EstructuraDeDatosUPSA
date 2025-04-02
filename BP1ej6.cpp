//Almacén de Productos: Crea la clase Producto, con los siguientes atributos:
//- id (numerico)
//- nombre
//- precio
//- cantidad en stock
//Luego, implementa la clase Almacen, que guarda objetos de la clase Producto en una matriz, donde:
//- Cada fila representa una categoría de productos.
//- Cada columna representa una ubicación en stock.
//Debe permitir:
//- Agregar un producto en una posición específica de la matriz.
//- Calcular el total de productos en una categoría (suma de las cantidades enuna fila).
#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

class Producto {
private:
    int id;
    string nombre;
    double precio;
    int cantidad;

public:

    Producto() : id(0), nombre(""), precio(0.0), cantidad(0) {}

    Producto(int _id, const string &_nombre, double _precio, int _cantidad)
        : id(_id), nombre(_nombre), precio(_precio), cantidad(_cantidad) {}

    int getId() const { return id; }
    string getNombre() const {
        return nombre;
    }
    double getPrecio() const {
        return precio;
     }
    int getCantidad() const {
        return cantidad;
     }
    void setId(int _id) {
        id = _id;
    }
    void setNombre(const string &_nombre) {
        nombre = _nombre;
    }
    void setPrecio(double _precio) {
        precio = _precio;
    }
    void setCantidad(int _cantidad) {
        cantidad = _cantidad;
    }
};


class Almacen {
private:
    Matrix<Producto, 3, 4> productos;

public:

    void agregarProducto(int categoria, int posicion, const Producto &p) {
        productos.set(categoria, posicion, p);
    }

    int totalProductosEnCategoria(int categoria) {

        int total = 0;
        for (int col = 0; col < productos.numCols(); col++) {

            Producto p = productos.at(categoria, col);
            total += p.getCantidad();
        }
        return total;
    }


    void imprimirAlmacen() {
        for (int fila = 0; fila < productos.numRows(); fila++) {
            cout << "Categoría " << fila << ": ";
            cout<<endl;

            for (int col = 0; col < productos.numCols(); col++) {
                Producto p = productos.at(fila, col);
                cout << " ID:" << p.getId() <<endl
                     << " Nombre:" << p.getNombre()<<endl
                     << " Precio:" << p.getPrecio()<<endl
                     << " Cantidad:" << p.getCantidad()<<endl;
            }
            cout << endl<<endl;
        }
    }
};

int main() {
    Almacen almacen;

    Producto p1(01, "Sillon negro personal", 750.0, 3);
    Producto p2(02, "Almohadón 'Himalaya' ", 78.0, 300);
    Producto p3(03, "Licuadora Steeless", 999.99, 99);

    almacen.agregarProducto(0, 0, p1);

    almacen.agregarProducto(0, 1, p2);

    almacen.agregarProducto(1, 0, p3);

    cout << "Contenido del Almacén:" << endl;
    almacen.imprimirAlmacen();

    cout << "Total de productos en la categoría 0: "
         << almacen.totalProductosEnCategoria(0) << endl;

    cout << "Total de productos en la categoría 1: "
         << almacen.totalProductosEnCategoria(1) << endl;

    cout << "Total de productos en la categoría 2: "
         << almacen.totalProductosEnCategoria(2) << endl;

    return 0;
}
