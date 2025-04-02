#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Vector {
  private:
    T* items;
    int size;
    int capacity;

  public:
    // Constructor
    Vector(int _capacity = 10) : size(0), capacity(_capacity) {
        items = new T[capacity];
    }

    // Destructor
    ~Vector() {
        delete[] items;
    }

    // Constructor de copia
    Vector(const Vector& other) {
        size = other.size;
        capacity = other.capacity;
        items = new T[capacity];  // Asignar nueva memoria
        for (int i = 0; i < size; i++) {
            items[i] = other.items[i];
        }
    }

    // Operador de asignación por copia
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] items;
            size = other.size;
            capacity = other.capacity;
            items = new T[capacity];
            for (int i = 0; i < size; i++) {
                items[i] = other.items[i];
            }
        }
        return *this;
    }

    // Métodos de acceso
    T& at(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fuera de rango");
        }
        return items[index];
    }

    const T& at(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fuera de rango");
        }
        return items[index];
    }

    void pushBack(const T& value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        items[size++] = value;
    }

    int getSize() const {
        return size;
    }

    void resize(int newCapacity) {
        if (newCapacity <= capacity) return;

        T* newItems = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
        capacity = newCapacity;
    }
    void print() const {
        if (size == 0) {
            cout << "Vector vacío" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }

};

#endif // VECTOR_H
