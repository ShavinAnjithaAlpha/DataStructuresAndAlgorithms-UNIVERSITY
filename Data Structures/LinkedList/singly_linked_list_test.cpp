#include<iostream>
#include<string>
#include "singly_linked_list.h"

using namespace std;

int main() {

    LinkedList<int> list;
    // add some values to the list
    list.push_back(1);
    list.push_back(2);
    list.push_front(3);
    list.push_front(4);

    // search for item
    cout << "search for item value 2 : " << list.search(3) << endl;

    // print the list
    cout << "list after inserting: \n";
    cout << list;
    cout << "size of the list: " << list.length() << endl;

    list.delete_back();
    cout << "\nlist after deleteing from back:\n";
    list.print_list();

    list.delete_front();
    cout << "\nlist after deleteing from front:\n";
    list.print_list();
    cout << endl;

    list.push_back(9);
    list.push_back(10);
    cout << "list after inserting: \n";
    list.print_list();

    list.delete_item(9);
    cout << "list after delete: \n";
    list.print_list();

    cout << "\nlist after delete head:\n";
    list.delete_item(3);
    list.print_list();

    // access item through bracket notation
    cout << "\nfrist item in the list is " << list[0] << endl;


    cout << "enter e;ement to insert to an list >> ";
    cin >> list;

    cout << "list after inserting new value from input stream : " << list;



}