#include <iostream>
#include "LinkedList.h"
using namespace std;
bool Palindrome(LinkedList<int> &list) {
    LinkedList<int> reversed = list.invert();
    if (list.getSize() != reversed.getSize()) return false;

    for (int i = 0; i < list.getSize(); i++) {
        if (list.at(i) != reversed.at(i)) {
            return false;
        }
    }

    return true;
}
int main(){
    int P;
        LinkedList<int> list;
        list.pushBack(1);
        list.pushBack(2);
        list.pushBack(3);
        list.pushBack(2);
        list.pushBack(1);

        list.print();

        P=Palindrome(list);
        if (P==true){
        cout <<"Es palindrome"<<endl;
    }
    else{
        cout<<"No es palindrome"<<endl;
    }

        return 0;
    }


