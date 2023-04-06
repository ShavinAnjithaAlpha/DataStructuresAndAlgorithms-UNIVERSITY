#include<iostream>
#include<stdexcept>
#include "linked_stack.h"

using namespace std;

int main() {

    LinkedStack<int> stack;
    stack.display();

    // push some values
    stack.push(4);
    stack.push(7);
    stack.push(8);
    stack.push(12);
    cout << "stack after some pushings: ";
    stack.display();

    stack.pop();
    stack.pop();
    cout << "stack after some popings: ";
    stack.display();

    cout << "\nis stack is empty: " << stack.is_empty() << endl;
    stack.pop();
    stack.pop();
    try{
        stack.pop();
    } catch (overflow_error& exp) {
        cout << exp.what() << endl;
    }

    // push some values
    stack.push(0);
    stack.push(8);
    stack.push(1);
    stack.push(6);
    cout << "stack after some pushings again: ";
    stack.display();



}