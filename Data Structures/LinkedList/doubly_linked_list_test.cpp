#include<iostream>
#include<string>
#include "doubly_linked_list.h"

using namespace std;

int main() {

    DoubleLinkedList<int> list;
    // add some values to the list
    list.push_back(111);
    list.push_back(2);
    list.push_front(3);
    list.push_front(4);

    // search for item
    // cout << "search for item value 2 : " << list.search(3) << endl;

    // print the list
    cout << "list after inserting: " << list;
    cout << "size of the list: " << list.length() << endl;

    list.delete_back();
    cout << "\nlist after deleteing from back: " << list;

    list.delete_front();
    cout << "\nlist after deleteing from front: " << list;
    cout << endl;

    list.push_back(9);
    list.push_back(10);
    cout << "list after inserting: " << list;

    list.delete_element(9);
    cout << "list after delete: " << list;

    cout << "\nlist after delete head: ";
    list.delete_element(3);
    cout << list;

    // access item through bracket notation
    cout << "\nfrist item in the list is " << list[0] << endl;


    cout << "enter e;ement to insert to an list >> ";
    cin >> list;

    cout << "list after inserting new value from input stream : " << list;

    list.insert(999, 1);
    cout << "list after insert an 99 into index 1 : " << list;



}