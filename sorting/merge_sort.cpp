#include<iostream>

using namespace std;

void merge_sort(int*, const int, int); // prototype for merge sort
void print_array(const int*, const size_t); // prototype for print the array

int main() {

    const int SIZE{10};

    int arr[SIZE]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print_array(arr, SIZE);
    merge_sort(arr, 0, SIZE - 1);
    print_array(arr, SIZE);

}

void merge_sort(int arr[], int start, int end) {

    if (start == end) {
        return;
    } else {
        // recursively merge sort the array
        // find the middle point
        int middle = (end - start) / 2 + start;
        merge_sort(arr, start, middle);
        merge_sort(arr, middle + 1, end);

        // merge the two soretd sub arrays
        // copies the content of the array to new arrays
        int n1{middle - start + 1};
        int n2{end - middle};

        int array1[n1], array2[n2];
        for (unsigned int i{0}; i < n1; i++) {
            array1[i] = arr[start + i];
        }

        for (unsigned int i{0}; i < n2; i++) {
            array2[i] = arr[middle + 1 + i];
        }

        // then replace the content of the primary array with the soretd items
        int i{0}, j{0}, k{start};
        while (i < n1 && j < n2) {
            if (array1[i] < array2[j]) {
                arr[k] = array1[i];
                i++;
            } else if (array1[i] >= array2[j]) {
                arr[k] = array2[j];
                j++;
            }
            k++;
            
        }

        if (i < n1) {
            do {
                arr[k] = array1[i];
                i++;
                k++;
            } while (i < n1);
        }

        if (j < n2) {
            do {
                arr[k] = array2[j];
                j++;
                k++;
            } while (j < n2);
        }

    }

}

void print_array(const int arr[], const size_t length) {

    for (unsigned int i{0}; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}