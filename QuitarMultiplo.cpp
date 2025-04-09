#include <iostream>
#include "LinkedList.h"
using namespace std;
LinkedList<int> QuitarMultiplo(const LinkedList<int> &list, int mul) {
    LinkedList<int> R;
    for (int i = 0; i < list.getSize(); i++) {
        int current = list.at(i);
        if (current % mul != 0) {
            R.pushBack(current);
        }
    }

    return R;
}
int main() {
    LinkedList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);

    cout << "La lista es: "<<endl;
    list.print();

    int mul = 2;
    LinkedList<int> SinMultiplos = QuitarMultiplo(list, mul);

    cout << "Lista sin múltiplos de " << mul << " es: "<<endl;
    SinMultiplos.print();

    return 0;
}

