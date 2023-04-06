#include<iostream>
#include<stdexcept>

#ifndef LINKED_STACK_H
#define LIINKED_STACK_H

template<typename T>
class Node {
public:
    Node(const T& data, Node<T>* prev = nullptr) : data{data}, prev{prev} {
        // empty constrctor
    }

    T data;
    Node<T>* prev;

};

template<typename T>
class LinkedStack {
public:

    LinkedStack() : top{nullptr} {
        // empty constructor
    }

    void push(const T& data) {

        if (is_empty()) {
            top = new Node<T>(data, nullptr);
            return;
        }

        Node<T>* new_node{new Node<T>(data, top)};
        top = new_node;
    }

    T pop() {

        if (top == nullptr) {
            throw std::overflow_error("stack underflow error");
        }

        T data{top->data}; // store the data in temp variable
        Node<T>* tmp{top};
        top = top->prev; // set the new top pointer
        delete tmp; // delete the top node

        return data;

    }

    bool is_empty() const {
        return top == nullptr;
    }

    void display() const {
        
        if (top == nullptr) {
            std::cout << "stack is empty" << std::endl;
            return;
        }

        // print the stack from top to the bottom
        for (Node<T>* tmp{top}; tmp != nullptr; tmp = tmp->prev) {
            std::cout << tmp->data << " ";
        }
        std::cout << std::endl;
    }

private:
    Node<T>* top;

};

#endif