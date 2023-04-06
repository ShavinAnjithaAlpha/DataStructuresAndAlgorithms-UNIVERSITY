#include<iostream>
#include<ctime>
#include<random>
#include<sys/time.h>
#include<cstdlib>

#include "array_stack.h"
#include "linked_stack.h"

using namespace std;

int main() {

    int array_stack_size;
    cout << "Enter array stack size: ";
    cin >> array_stack_size;

    // create two stack from linked stack and array stack
    LinkedStack<int> linked_stack;
    ArrayStack<int> array_stack(array_stack_size);

    struct timeval start, end;
    srand(static_cast<unsigned int>(time(0)));

    long array_stack_time, linked_stack_time;

    // start time test for array stack
    gettimeofday(&start, NULL);
    // performe the opeartion on them
    for (int i{0}; i < 10; i++) {
        array_stack.push(100 + i*i);
    }

    cout << "\nArray Stack after pushing : ";
    array_stack.display();

    for (int i{0}; i < 5; i++) {
        array_stack.pop();
    }
    cout << "Array Stack after poping: ";
    array_stack.display();

    for (int i{0}; i < 4; i++) {
        array_stack.push(250 - i*i*i);
    }
    cout << "Array Stack after pushing: ";
    array_stack.display();

    gettimeofday(&end, NULL);
    array_stack_time = (end.tv_usec - start.tv_usec) + (end.tv_sec - start.tv_sec) * 1000000;



    // start time test for linked stack
    gettimeofday(&start, NULL);
    // performe the opeartion on them
    for (int i{0}; i < 10; i++) {
        linked_stack.push(100 + i*i);
    }

    cout << "\nLinked Stack after pushing : ";
    linked_stack.display();

    for (int i{0}; i < 5; i++) {
        linked_stack.pop();
    }
    cout << "Linked Stack after poping: ";
    linked_stack.display();

    for (int i{0}; i < 4; i++) {
        linked_stack.push(250 - i*i*i);
    }
    cout << "Linked Stack after pushing: ";
    linked_stack.display();

    gettimeofday(&end, NULL);
    linked_stack_time = (end.tv_usec - start.tv_usec) + (end.tv_sec - start.tv_sec) * 1000000;


    // display thr time results
    cout << "\ntime taken for array stack: " << array_stack_time << endl;
    cout << "time taken for linked stack: " << linked_stack_time << endl;

}