//Simetría en un Vector: Implementa una función que verifique si un vector de
//enteros es simétrico.
//Ejemplo: [1, 2, 3, 2, 1] es simétrico, pero [1, 2, 3, 4] no lo es
#include <iostream>
#include "Vector.h"

using namespace std;

bool simetrico(const Vector<int> &v){
    int j= v.getSize()- 1, i=0;
    for(i=0; i<v.getSize()/2; i++){
        if(v.at(i) != v.at(j)){
            return false;
        }
        j--;
    }
    return true;
    }
    int main (){
        int i;
        Vector <int> v;
        v.pushBack (1);
        v.pushBack (2);
        v.pushBack (3);
        v.pushBack (2);
        v.pushBack (1);
        for (i=0; i<5; i++){
            cout<< v.at(i)<<" ";
        }
        cout<<endl;
        if (simetrico(v)){
        cout<<"El vector es simetrico"<<endl;
        }
        else{
            cout<<"El vector no es simetrico"<<endl;
         }
        return 0;
}
