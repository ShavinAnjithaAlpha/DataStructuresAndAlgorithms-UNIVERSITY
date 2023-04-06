#include<iostream>
#include "array_stack.h"

using namespace std;

int main() {

    ArrayStack<int> stack{10};
    stack.push(10);
    stack.push(45);

    cout << stack.pop();

    stack.display();

}