#include<iostream>  
#include "hashtable.h"

int main() {

    HashMap<int> map;
    map.insert("shavin", 12);
    map.insert("Omalya", 44);
    map.insert("reshani", 45);
    map.insert("pytha", 123);
    map.insert("shyamal", 8);
    map.insert("kasun", 78);

    std::cout << map;
    return 0;
}