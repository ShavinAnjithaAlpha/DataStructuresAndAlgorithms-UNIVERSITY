#include<iostream>
#include<stdexcept>
#include"stack.h"

using namespace std;

int main() {

    ArrayStack<int, 10> stack;
    stack.push(10);
    stack.push(11);
    stack.push(7);
    stack.push(89);

    cout << "stack after 4 pushings : " << stack;
    cout << "top element : " << stack.top_el() << endl;

    stack.pop();
    stack.pop();
    stack.pop();

    cout << "stack after 3 pops : " << stack;
    stack.pop();
    cout << "stack is empty : " << ((stack.empty()) ? "yes" : "no") << endl;

    try{
        stack.pop();
    } catch (underflow_error& exp) {
        cout << endl << exp.what() << endl;
    }

    cout << "\nLinked Stack Operations: \n";
    // create an linked stack
    LinkedStack<int> lstack;
    lstack.push(10);
    lstack.push(11);
    lstack.push(7);
    lstack.push(89);

    cout << "stack after 4 pushings : " << lstack;
    cout << "top element : " << lstack.top_el() << endl;

    lstack.pop();
    lstack.pop();
    lstack.pop();

    cout << "stack after 3 pops : " << lstack;
    lstack.pop();
    cout << "stack is empty : " << ((lstack.empty()) ? "yes" : "no") << endl;

    try{
        lstack.pop();
    } catch (underflow_error& exp) {
        cout << endl << exp.what() << endl;
    }



}