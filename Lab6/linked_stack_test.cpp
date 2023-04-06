#include<iostream>
#include "linked_stack.h"

using namespace std;

int main() {

    LinkedStack<int> stack;
    stack.display();
    stack.push(44);
    stack.display();
    stack.push(12);
    stack.push(74);



    stack.display();
    cout << stack.pop() << endl;
    stack.display();

}