#include <iostream>
#include "LinkedList.h"
using namespace std;
LinkedList <int> QuitarDupli(const LinkedList<int>&list){
    LinkedList<int> R;
    for(int i=0;i<list.getSize();i++){
        int current=list.at(i);
        bool Existe = false;

    for(int j=0;j<R.getSize();j++){
        if(R.at(j)==current){
            Existe=true;
            break;
        }
    }
    if(!Existe){
        R.pushBack(current);
    }
    }
    return R;
}
int main(){
    LinkedList <int>list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(2);
    list.pushBack(1);
    list.pushBack(1);
    cout<< "La lista es: "<<endl;
    list.print();
    LinkedList <int> NoDupli = QuitarDupli(list);
    cout<<"Lista sin duplicados: "<<endl;
    NoDupli.print();
    return 0;
}
