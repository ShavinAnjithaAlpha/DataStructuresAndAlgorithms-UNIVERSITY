#include<iostream>
#include<stdexcept>

#ifndef STACK_H
#define STACK_H

template<class T, int capacity = 30>
class ArrayStack {
    // stream insertion operator for print the stack on console
    friend std::ostream& operator<<(std::ostream& out, const ArrayStack<T, capacity>& stack) {

        for (int i{0}; i <= stack.top; i++) {
            out << stack.arr[i] << " ";
        }
        out << std::endl;
        return out;

    }

public:
    // constrctors
    ArrayStack() : top{-1}, arr{new T[capacity]} {
        // empty body
    }

    // destructor
    ~ArrayStack() {
        delete[] arr;
    }

    // basic coperations on stack
    bool empty() const {
        return top == -1;
    }

    bool full() const {
        return top == capacity - 1;
    }

    void clear() {
        top = -1;
    }

    size_t size() const {
        return top + 1;
    }

    T& top_el() const {
        if (top == -1) {
            throw std::underflow_error("stack is empty");
        }
        return arr[top];
    } 

    T pop() {
        if (top == -1) {
            throw std::underflow_error("stack is empty");
        }

        T temp = arr[top--];
        return temp;
    }

    void push(const T& data) {
        if (top == capacity - 1) {
            throw std::overflow_error("stack is full");
        }

        arr[++top] = data;
    }


private:
    T* arr;
    int top;
};

template<typename T>
class Node {
public:
    Node() : next{nullptr} {
        // empty body
    }

    Node(const T& data, Node<T>* next = nullptr) : data{data}, next{next} {
        // empty body
    }

    T data;
    Node<T>* next;
};

template<typename T>
class LinkedStack {

    friend std::ostream& operator <<(std::ostream& out, const LinkedStack<T>& stack) {

        Node<T>* current{stack.top};
        while (current != nullptr) {
            out << current->data << " ";
            current = current->next;
        }
        out << std::endl;
        return out;
    }

public:
    // constrcutors
    LinkedStack() : top{nullptr}, size{0} {} // default constructor
    // explicit constructor;
    LinkedStack(const T& data) : size{1} {
        top = new Node<T>(data);
    }

    // destructor
    ~LinkedStack() {

        Node<T> *current, *prev;
        while (current != nullptr) {
            prev = current;
            current = current->next;
            delete prev;
        }

    }

    // basc operations on stack
    void push(const T& data) {
        Node<T>* node{new Node<T>(data, top)};
        top = node;
        size++;
    }

    T& top_el() const {
        return top->data;
    }

    T pop() {

        if (top == nullptr) {
            throw std::underflow_error("stack is empty");
        }

        Node<T>* temp{top};
        T data = temp->data;
        top = top->next;
        delete temp;
        size--;

        return data;

    }

    void clear() {

        Node<T> *current{top}, *prev{nullptr};
        while (current != nullptr) {
            prev = current;
            current = current->next;
            delete prev;
        }

        size = 0;

    }

    bool empty() const {
        return top == nullptr;
    }

    size_t length() const {
        return size;
    }

private:
    Node<T>* top;
    size_t size;
};

#endif