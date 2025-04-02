//Seguimiento del Rendimiento Académico: Crea la clase GestionAcademica, que
//administre un vector de objetos de la clase Estudiante, con atributos:
//- registro
//- nombre
//- vector de calificaciones
//Debe permitir:
//- Calcular el promedio de calificaciones de cada estudiante.
//- Obtener el promedio general del grupo de estudiantes.
#include "Vector.h"
#include <iostream>
using namespace std;

class Estudiante {
  private:
    int registro;
    string nombre;
    Vector<int> calificaciones;

  public:
    Estudiante() : registro(0), nombre("Desconocido") {}

    Estudiante(int _registro, string _nombre, int _p1, int _p2, int _p3)
        : registro(_registro), nombre(_nombre) {
        calificaciones.pushBack(_p1);
        calificaciones.pushBack(_p2);
        calificaciones.pushBack(_p3);
    }

    void setRegistro(int _registro) {
         registro = _registro;
        }
    int getRegistro() const {
        return registro;
    }

    void setNombre(string _nombre) {
        nombre = _nombre;
    }
    string getNombre() const {
        return nombre;
    }

    const Vector<int>& getCalificaciones() const {
         return calificaciones;
         }


    void mostrar() const {
        cout << "Registro: " << registro << ", Nombre: " << nombre << ", Calificaciones: ";
        for (int i = 0; i < calificaciones.getSize(); i++) {
            cout << calificaciones.at(i) << " ";
        }
        cout << endl;
    }
};

class GestionAcademica {
  private:
    Vector<Estudiante> estudiantes;

  public:
    void agregar(const Estudiante& e) { estudiantes.pushBack(e); }

    float promedioEstudiante(const Estudiante& e) const { // Pasar por referencia
        const Vector<int>& calificaciones = e.getCalificaciones();
        if (calificaciones.getSize() == 0) return 0;

        float suma = 0;
        for (int i = 0; i < calificaciones.getSize(); i++) {
            suma += calificaciones.at(i);
        }
        return suma / calificaciones.getSize();
    }

    float promedioGrupo() const {
        if (estudiantes.getSize() == 0) return 0;

        float sumaTotal = 0;
        for (int i = 0; i < estudiantes.getSize(); i++) {
            sumaTotal += promedioEstudiante(estudiantes.at(i));
        }
        return sumaTotal / estudiantes.getSize();
    }

    void mostrarPromedioE() const {
        for (int i = 0; i < estudiantes.getSize(); i++) {
            estudiantes.at(i).mostrar();
            cout << "Promedio del estudiante: " << promedioEstudiante(estudiantes.at(i)) << endl;
        }
    }
};

int main() {
    Estudiante E1(109, "Pilar", 52, 100, 44);
    Estudiante E2(162, "Abel", 61, 23, 52);
    Estudiante E3(819, "Julio", 88, 95, 90);

    GestionAcademica gestor;
    gestor.agregar(E1);
    gestor.agregar(E2);
    gestor.agregar(E3);

    cout << "Lista de estudiantes:" << endl;
    gestor.mostrarPromedioE();

    cout << "Promedio general del grupo: " << gestor.promedioGrupo() << endl;

    return 0;
}


