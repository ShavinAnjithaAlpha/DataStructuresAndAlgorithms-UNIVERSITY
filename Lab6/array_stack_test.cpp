#include<iostream>
#include "array_stack.h"

using namespace std;

int main() {

    ArrayStack<int> stack{10};
    // pushing some values
    stack.push(10);
    stack.push(45);
    stack.push(12);
    stack.push(74);
    stack.push(23);
    cout << "stack after some pushings: ";
    stack.display();

    stack.pop();
    stack.pop();
    stack.pop();

    cout << "stack after some popings operations: ";
    stack.display();

    stack.pop();
    stack.pop();
    try{
        stack.pop();
    } catch(overflow_error& exp) {
        cout << exp.what() << endl;
    }

    cout << "\nstack after futher popings: ";
    stack.display();

}