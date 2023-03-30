#include<iostream>

using namespace std;


void quick_sort(int*, const int, const int); // function prototype
void print_array(int*, const size_t); // function for print a array

int main() {

    const size_t SIZE{10};
    // declare a sample integer array
    int arr[SIZE]{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    cout << "array before sorted:" << endl;
    print_array(arr, SIZE);

    // sort the array
    quick_sort(arr, 0, SIZE - 1);
    cout << "\narray after sorted:" << endl;
    print_array(arr, SIZE);

}

void quick_sort(int arr[], const int start, const int end) {

    if (start >= end) { // base case
        return;
    }

    int pivot{arr[end]}; // set up the pivot as the end of the array segment
    int i{start - 1}, j{start}, temp;
    while (j < end) {
        if (arr[j] < pivot) {
            // swapping
            temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    // place the pivot
    temp = arr[++i];
    arr[i] = pivot;
    arr[end] = temp;

    // recursively called quick sort function
    quick_sort(arr, start, i - 1);
    quick_sort(arr, i + 1, end);

}


void print_array(int arr[], const size_t size) {

    for (size_t i{0}; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}