#include<iostream>
#include<stdexcept>

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

// inline functions for calculating LEFT, RIGHT, and PARENT for Max-Heap
inline int left(int i) {
    return 2 * i;
}

inline int right(int i) {
    return 2 * i + 1;
}

inline int parent(int i) {
    return i / 2; // ceiling of the value i/2
}

template<typename T>
class MaxHeap {

    // default constructor
    MaxHeap() : length{127}, arr{new T[length]} {
        // empty constructor
    }
    // explicit one parameter constructor (array length)
    explicit MaxHeap(const T* i, ...) : arr{i} {
        length = sizeof(arr) / sizeof(T);
        size = length;

    }

    // destructor
    ~MaxHeap() {
        // reallocat the dynamically created array
        delete [] arr;
    }

    // utility functions
    size_t get_length() const {
        return length;
    }

    size_t heap_size() const {
        return size;
    }

    // heap sort method
    void heap_sort() {
        
        size_t heap_size{size};

        build_max_heap() // build the max heap 
        // now maximum value at the root of the array
        for (int i{size}; i > 1; i--) {
            // swap the values at the i and last index of heap
            int temp{*(arr + i - 1)};
            *(arr + i - 1) = *(arr + size - 1);
            *(arr + size - 1) = temp;
            // decrement the heap size by one
            size--;
            max_heapify(1); // max heapify the heap at root

        }

        size = heap_size; // reset the heap size value

    }


private:

    // helper methods for max heap 
    void max_heapify(int i) {

        // get the left and right sub trees
        int l = left(i), r = right(i), int largest;
        // check whether there is left sub tree and determine the largest value
        if (l <= heap_size() && arr[l - 1] > arr[i - 1]) {
            largest = l;
        } else {
            largest = i;
        }
        // check whether there is a right sub tree and determine the largest value
        if (r <= heap_size() && arr[r - 1] > largest) {
            largest = r;
        }


        // check whether root is also follow the max heap property by checking largest index and i
        if (largest != i) {
            // largest is either left or right sub tree's root
            // do the swaps
            int temp = arr[largest - 1];
            *(arr + largest - 1) = *(arr + i - 1);
            *(arr + i - 1) = temp;
            // recursively called to the sub tree which is index is largest for max-heapifying
            max_heapify(largest);
        }
    }

    // method for build max heao from bottom to uo manner
    void build_max_heap() {
        // start from middle of the array heapify the array by called the max-heapify method
        for (int i = size / 2; i > 0; i--) {
            max_heapify(i);
        }

    }

    // fields of the max heap
    T* arr;
    size_t length;
    size_t size{0};
};

#endif