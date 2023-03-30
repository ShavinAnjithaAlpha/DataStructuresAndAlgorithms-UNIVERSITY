#include<iostream>

using namespace std;

void iterative_quick_sort(int*, const int); // function prototype for quick sort
void print_array(int*, const size_t); // function prototype for print a array

int main() {

    const int SIZE{10};
    // declare a sample integer array
    int arr[SIZE]{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    cout << "array before sorted:" << endl;
    print_array(arr, SIZE);

    // sort the array
    iterative_quick_sort(arr, SIZE);
    cout << "\narray after sorted:" << endl;
    print_array(arr, SIZE);

}

void iterative_quick_sort(int arr[], const int size) {

    // create a auxillary stack to keep track on the positions
    int stack[size];
    // head of the stack
    int top{-1};

    // populate the stack with firt two indexes
    stack[++top] = 0;
    stack[++top] = size - 1;

    int start, end, pivot_index;
    while (top >= 0) {
        // extract last two indeices
        end = stack[top--];
        start = stack[top--];

        // choose the pivor point
        int pivot{arr[end]};
        int i{start - 1}, j{start}, temp;
        while (j < end) {
            if (arr[j] < pivot) {
                // swap the elements
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

        pivot_index = i;

        if (pivot_index - 1 > start) {
            stack[++top] = start;
            stack[++top] = pivot_index - 1;
        }

        if (pivot_index + 1 < end) {
            stack[++top] = pivot_index + 1;
            stack[++top] = end;
        }

    }

}


void print_array(int arr[], const size_t size) {

    for (size_t i{0}; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}