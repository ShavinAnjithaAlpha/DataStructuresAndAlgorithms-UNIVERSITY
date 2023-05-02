#include<iostream>
#include<stdexcept>

#ifndef MAX_PRIORITY_QUEUE_H
#define MAX_PRIORITY_QUEUE_H

// inline function for calculate the LEFT , RIGHT, and the PARENT indexes
inline int LEFT(int i) {
    return 2 * i;
}

inline int RIGHT(int i) {
    return 2 * i + 1;
}

inline int PARENT(int i) {
    return i / 2;
}

template<typename T>
class MaxPriorityQueue {

    friend std::ostream& operator <<(std::ostream& out, const MaxPriorityQueue<T>& queue) {

        T *arr = queue.arr;
        for (int i{0}; i < queue.heap_size; i++) {
            out << arr[i] << " ";
        }
        return out;

    }

public:
    // default constructor
    MaxPriorityQueue() : length{127}, arr{new T[length]} {}
    
    // utility methods
    T maximum() const {
        return arr[0]; // max heap gurantee that maximum is always at the root of the array
    }


    T extract_maximum() {

        if (heap_size < 1) 
            throw std::underflow_error("queue is empty");

        T max = arr[0]; // store the maximum value of the array
        arr[0] = arr[heap_size - 1]; // fill the root with last element of the heap
        heap_size--; // reduce the heap size by one;
        max_heapify(1); // heapify the root for restructured the max heap
        return max;

    }

    void increase_key(int i, T key) {

        if (arr[i - 1] > key) 
            throw std::invalid_argument("existing key is greater than the inserted one ");
        
        arr[i - 1] = key;
        while (i > 1 && arr[PARENT(i) - 1] < arr[i - 1]) {
            // swap the values
            int temp{arr[i - 1]};
            *(arr + i - 1) = *(arr + PARENT(i) - 1);
            *(arr + PARENT(i) - 1) = temp;
            i = PARENT(i); // set the new i to the parent index -- go up to the max heap
        }

    }

    void insert(const T& key) {

        if (heap_size >= length) 
            throw std::overflow_error("queue is full");

        // increase the heap size
        heap_size++;
        arr[heap_size - 1] = key;
        size_t i{heap_size};
        while (i > 1 && arr[PARENT(i) - 1] < arr[i - 1]) {
            // swap the values
            int temp{arr[i - 1]};
            *(arr + i - 1) = *(arr + PARENT(i) - 1);
            *(arr + PARENT(i) - 1) = temp;
            i = PARENT(i); // set the new i to the parent index -- go up to the max heap
        }

    }



private:
    // helper methods
    void build_max_heap() {

        for (int i = heap_size / 2; i > 0; i--) {
            max_heapify(i);
        }

    }

    void max_heapify(int i) {
        // calculating the left, right indexes
        int left = LEFT(i), right = RIGHT(i), largest;
        // check for left sub element
        if (left <= heap_size && arr[left - 1] > arr[i - 1]) {
            largest = left;
        } else {
            largest = i;
        }

        // check for right sub element
        if (right <= heap_size && arr[right - 1] > arr[largest - 1]) {
            largest = right;
        }

        // swap the values if largest index is either left or right index
        if (largest != i) {
            // swap the largest and i index values
            int temp{arr[largest - 1]};
            *(arr + largest - 1) = *(arr + i - 1);
            *(arr + i - 1) = temp;
            // recursively called to max heapify method for reorganize the heap
            max_heapify(largest);
        }

    }

    // queue attributes
    size_t length;
    size_t heap_size{0};
    T* arr;
};

#endif