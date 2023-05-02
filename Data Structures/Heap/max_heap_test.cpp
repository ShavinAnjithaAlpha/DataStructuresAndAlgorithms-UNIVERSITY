#include<iostream>
#include "max_heap.h"

using namespace std;

int main() {

    MaxHeap<int> heap{10, 5, 4, 4, 1, 2, 0, 7, 6, 8, 9}; // initialize a unsorted heap using initializer list
    // print the heap before sort
    cout << "Heap before sort : " << heap << endl;
    heap.heap_sort(); // sort the heap 
    cout << "Heap after sort : " << heap << endl; // print the sorted array


}