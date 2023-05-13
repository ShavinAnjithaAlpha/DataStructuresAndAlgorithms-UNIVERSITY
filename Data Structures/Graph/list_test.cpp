#include<iostream>
#include"linked_list.h"

int main() {

    LinkedList<int> list;
    list.insert_last(5);
    list.insert_last(7);
    list.insert_last(9);
    list.insert_first(3);
    std::cout << list;

    list.delete_item(7);
    std::cout << list;

    list.delete_item(9);
    std::cout << list;

    list.delete_item(3);
    std::cout << list;

}