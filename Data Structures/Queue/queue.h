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

#endif