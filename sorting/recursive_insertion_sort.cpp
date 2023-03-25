#include<iostream>
#define SIZE 10

using namespace std;

void recursive_insertion_sort(int array[], const size_t length);

void print_array(const int* arr, const size_t length);

int main() {

    // creating an array
    int arr[SIZE] = {1, 0, 9, -6, 4, 3, 8, 10, 2, -2};

    print_array(arr, SIZE);
    recursive_insertion_sort(arr, SIZE); // sort the array recursively
    print_array(arr, SIZE); // print the sorted array

    return 0;
}

void recursive_insertion_sort(int array[], const size_t length) {

    size_t offset{length - 1};
    if (length == 1) {
        return;
    } else {
        // recursively sort the array
        recursive_insertion_sort(array, length - 1);
    }

    // adding the last value of 
    int current_value{array[offset]};
    int j{(int) offset - 1};
    while (j >= 0 && current_value < array[j]) {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = current_value;
}

void print_array(const int* arr, const size_t length) {

    for (size_t i{0}; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}