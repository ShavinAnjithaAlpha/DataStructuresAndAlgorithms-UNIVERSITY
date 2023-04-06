#include<iostream>
#include<stdexcept>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

template<typename T>
class ArrayStack {
public:

    explicit ArrayStack(int capacity) : top{-1}, capacity{capacity} {
        arr = new T[capacity];
    }

    void push(const T& data) {
        if (top >= capacity - 1) { // chec for stack overflow
            throw std::overflow_error("stack overflow error");
        }

        arr[++top] = data; // assign new value to the incremented index

    }

    T pop() {

        if (is_empty()) throw std::overflow_error("stack underflow error");

        int tmp = top--; // decrement the top index and store prevoius index
        return arr[tmp]; // return the last element

    }

    bool is_full() const {
        return top >= capacity - 1;
    }

    bool is_empty() const {
        return top == -1;
    }

    T stack_top() const {
        if (is_empty()) {
            throw std::overflow_error("stack is empty");
        }

        return arr[top];
    }

    void display() const {

        for (size_t i{0}; i <= top; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

    }

private:
    
    int capacity;
    T* arr;
    int top;
};

#endif