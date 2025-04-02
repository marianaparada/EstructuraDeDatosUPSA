//Registro de Calificaciones: Crea la clase GestionCalificaciones, que administre
//una matriz de calificaciones, donde:
//- Las columnas representan distintas materias o evaluaciones.
//Debe permitir:
//- Calcular el promedio de cada estudiante.
//- Obtener el promedio general del curso.
#include <iostream>
#include "Matrix.h"
using namespace std;


class GestionCalificaciones {
private:

    Matrix<double, 3, 4> calificaciones;

public:

    void setCalificacion(int estudiante, int materia, double nota) {
        calificaciones.set(estudiante, materia, nota);
    }


    double promedioEstudiante(int estudiante) {
        double suma = 0.0;
        int numMaterias = calificaciones.numCols();

        for (int col = 0; col < numMaterias; col++) {
            suma += calificaciones.at(estudiante, col);
        }
        return suma / numMaterias;
    }


    double promedioGeneral() {
        double sumaTotal = 0.0;
        int totalEstudiantes = calificaciones.numRows();
        int totalMaterias = calificaciones.numCols();
        int totalCalificaciones = totalEstudiantes * totalMaterias;

        for (int fila = 0; fila < totalEstudiantes; fila++) {
            for (int col = 0; col < totalMaterias; col++) {
                sumaTotal += calificaciones.at(fila, col);
            }
        }
        return sumaTotal / totalCalificaciones;
    }


    void imprimirCalificaciones() {
        cout << "Matriz de Calificaciones (Estudiantes x Materias):" << endl;
        calificaciones.print();
    }
};


int main() {

    GestionCalificaciones gestion;


    gestion.setCalificacion(0, 0, 50.5);
    gestion.setCalificacion(0, 1, 67.0);
    gestion.setCalificacion(0, 2, 51.0);
    gestion.setCalificacion(0, 3, 100.5);

    gestion.setCalificacion(1, 0, 11.0);
    gestion.setCalificacion(1, 1, 99.5);
    gestion.setCalificacion(1, 2, 80.0);
    gestion.setCalificacion(1, 3, 26.0);

    gestion.setCalificacion(2, 0, 72.0);
    gestion.setCalificacion(2, 1, 22.0);
    gestion.setCalificacion(2, 2, 33.5);
    gestion.setCalificacion(2, 3, 51.0);


    gestion.imprimirCalificaciones();


    cout << "Promedios por estudiante:" << endl;
    for (int est = 0; est < 3; est++) {
        cout << "Estudiante " << est
             << ": " << gestion.promedioEstudiante(est) << endl;
    }


    cout << "Promedio general del curso: "
         << gestion.promedioGeneral() << endl;

    return 0;
}
