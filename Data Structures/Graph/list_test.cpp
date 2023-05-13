#include<iostream>
#include"linked_list.h"

int main() {


    LinkedList<int> list;
    list.insert_last(5);
    list.insert_last(7);
    list.insert_last(9);
    list.insert_first(3);
    std::cout << list;

    std::cout << "Iterator : " << std::endl;
    for (LinkedList<int>::iterator iter{list.begin()}; iter != list.end(); ++iter) {
        std::cout << (*iter).data  << " ";
    }
    std::cout << std::endl;

    list.delete_item(7);
    std::cout << list;

    list.delete_item(9);
    std::cout << list;

    list.delete_item(3);
    std::cout << list;

}