#include<iostream>
#include<stdexcept>

#include "circular_linked_list.h"

using namespace std;

int main() {

    CircularLinkedList<int> list;
    list.push_back(5);
    list.push_back(7);
    list.push_back(9);
    cout << "list after insert in back : " << list;

    list.push_front(99);
    list.push_front(101);
    cout << "list after insert in back : " << list;

    list.delete_back();
    list.delete_front();

    cout << "list aftre deletion from front and back : " << list;

    list.delete_element(5);
    cout << "list after delete 5 : " << list;

}