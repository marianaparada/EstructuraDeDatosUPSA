#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList <int> Concat(const LinkedList<int>&list1, const LinkedList<int>&list2){
    LinkedList<int> R;
    for(int i=0;i<list1.getSize();i++){
        R.pushBack(list1.at(i));
    }
    for(int i=0;i<list2.getSize();i++){
        R.pushBack(list2.at(i));
    }
    return R;
}
int main(){
    LinkedList<int>list1;
    list1.pushBack(1);
    list1.pushBack(3);
    list1.pushBack(5);
    cout<<"La lista 1 es: "<<endl;
    list1.print();
    LinkedList<int>list2;
    list2.pushBack(2);
    list2.pushBack(4);
    list2.pushBack(6);
    cout<<"La lista 2 es: "<<endl;
    list2.print();
    LinkedList<int>R=Concat(list1,list2);
    cout<<"La lista concatenada es: "<<endl;;
    R.print();
    return 0;
}

