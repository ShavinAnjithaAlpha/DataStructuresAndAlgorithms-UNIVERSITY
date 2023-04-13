#include<iostream>
#include<stdexcept>

#ifndef QUEUE_H
#define QUEUE_H

template<typename T, int capacity = 100>
class Queue {

    friend std::ostream& operator <<(std::ostream& out, const Queue<T, capacity>& queue) {

        if (!queue.empty()) {
            if (queue.first <= queue.last) {
                for (int i{queue.first + 1}; i <= queue.last; i++) {
                    out << queue.arr[i] << " ";
                }
                out << std::endl;
            } else {

                for (int i{queue.first + 1}; i < capacity; i++) {
                    out << queue.arr[i] << " ";
                }
                for (int i{0}; i <= queue.last; i++) {
                    out << queue.arr[i] << " ";
                }
                out << std::endl;

            }
        }

    }

public:
    // constrctors
    Queue() :  arr{new T[capacity]}, first{-1}, last{-1} {
        // empty body
    }
    // destructor
    ~Queue() {
        delete[] arr;
    }

    // basic operations on queue
    void enqueue(const T& data) {
        if ((last + 1) % capacity == first) {
            throw std::overflow_error("queue is full");
        }

        last = (last + 1) % capacity;
        arr[last] = data;

    }

    T dequeue() {

        if (first == last) {
            throw std::underflow_error("queue is empty");
        }

        ++first;
        first %= capacity;
        return arr[first];

    }

    bool empty() const {
        return first == last;
    }

    void clear() {
        first = last = -1;
    }

    bool full() const {
        return first == 0 && last == capacity - 1;
    }

private:
    int first, last;
    T* arr;
};

template<typename T>
class Node {
public:
    // default constructor
    Node() : next{0} {}
    // explicit one parameter constrcutor
    explicit Node(const T& data, Node<T>* next = nullptr) : data{data}, next{next} {
        // empty body
    }

    T data;
    Node<T>* next;
};

template<typename T>
class LinkedQueue {
    // default constructor
    LinkedQueue() : head{nullptr}, tail{nullptr}, size{0} {
        // empty body
    }

    // explicit one parameter constructor
    explicit LinkedQueue(cons T& data) : size{1} {
        head = tail = new Node<T>(data);
    }

    // destructor
    ~LinkedQueue() {

        Node<T> *currentNode{head}, *prev{nullptr};
        while (currentNode != nullptr) {
            prev = currentNode;
            currentNode = currentNode->next;
            delete prev;
        }
    }

    // basic operations on linked queue
    void enqueue(const T& data) {

        Node<T>* node{new Node<T>(data)};
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;

    }

    T dequeue() {

        if (head == nullptr) {
            throw std::underflow_error("queue is empty");
        }

        Node<T>* temp{head};
        T data = head->data;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            delete temp;
        }
        size--;
        return data;

    }
    // return non-modifiable rvalue of first element of the queue
    T first() const {

        if (head == nullptr) {
            throw std::underflow_error("queue is empty");
        } 
        return head->data;

    }

    bool empty() const {
        return head == nullptr;
    }

    size_t length() const {
        retuen size;
    }

    void clear() {

        Node<T> *currentPtr{head}, *prev{nullptr};
        while (currentPtr != nullptr) {
            prev = currentPtr;
            currentPtr = currentPtr->next;
            delete prev;
        }

        head = tail = nullptr;
        size = 0;

    }

private:
    size_t size;
    Node<T> *head, *tail;
};

#endif