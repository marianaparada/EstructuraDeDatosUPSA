#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList <int> Alt(const LinkedList<int>&list1, const LinkedList<int>&list2){
    LinkedList<int> R;
    int size1= list1.getSize(), size2= list2.getSize(), size;
    if (size1 > size2) {
    size = size1;
    } else {
    size = size2;
}

        for(int i=0;i<size;i++){
            if(i<size1){
                R.pushBack(list1.at(i));
            }
            if(i<size2){
                R.pushBack(list2.at(i));
            }
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
    LinkedList<int>R=Alt(list1,list2);
    cout<<"La lista concatenada es: "<<endl;;
    R.print();
    return 0;
}
