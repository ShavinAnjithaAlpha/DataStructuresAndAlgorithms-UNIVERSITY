#include<iostream>  

struct Node {
    int x;
    int y;
};

class Object {
public:
    Object() {
        arr = new Node[10];
    }

    Node* arr;
};

int main() {

    Node arr[5] {5, 7};
    for (int i{0}; i < 5; i++) {
        std::cout << arr[i].x << std::endl;
        std::cout << arr[i].y << std::endl << std::endl;
    }

    Object obj;
    for (int i{0}; i < 10; i++) {
        std::cout << obj.arr[i].x << std::endl;
    }

    return 0;

}