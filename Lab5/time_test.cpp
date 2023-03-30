#include<iostream>
#include<ctime>
#include<sys/time.h>
#include<iomanip>
#include<cstdlib>
#include<random>

using namespace std;

void recursive_quick_sort(int*, const int, const int); // function prototype
void iterative_quick_sort(int*, const int);
void build_array_for_worst(int*, const int);
void build_array_for_average(int*, const int);
void copy_array(int*, int*, const int);

int main() {

    struct timeval start, end;
    srand(static_cast<unsigned int>(time(0)));

    const int TEST_CASES{10};
    int lengths[10]{1000, 4000, 8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};

    cout << setw(10) << "length" << setw(15) << right << "recursive" << setw(15) << "iterative" << endl;
    cout << endl;

    cout << "Worst Case:" << endl;
    for (int length : lengths) {

        long recursive_time{0}, iterative_time{0};
        // arrays for iterative and recursive sort
        int arr_rec[length], arr_iter[length];
        for (int k{0}; k < TEST_CASES; k++) {
            build_array_for_worst(arr_rec, length);
            build_array_for_worst(arr_iter, length);

            gettimeofday(&start, NULL);
            ios_base::sync_with_stdio(false);
            recursive_quick_sort(arr_rec, 0, length - 1);
            gettimeofday(&end, NULL);
            ios_base::sync_with_stdio(true);

            recursive_time += (end.tv_usec - start.tv_usec) + (end.tv_sec - start.tv_sec) * 1000000;

            gettimeofday(&start, NULL);
            ios_base::sync_with_stdio(false);
            iterative_quick_sort(arr_iter, length - 1);
            gettimeofday(&end, NULL);
            ios_base::sync_with_stdio(true);

            iterative_time += (end.tv_usec - start.tv_usec) + (end.tv_sec - start.tv_sec) * 1000000;


        }

        cout << setw(10) << length << setw(15) << right << recursive_time / TEST_CASES << setw(15)
            << iterative_time / TEST_CASES << endl;




    }

    cout << "\nAverage Case:" << endl;
    for (int length : lengths) {

        long recursive_time{0}, iterative_time{0};
        // arrays for iterative and recursive sort
        int arr_rec[length], arr_iter[length];
        for (int k{0}; k < TEST_CASES; k++) {
            build_array_for_average(arr_rec, length);
            copy_array(arr_iter, arr_rec, length);

            gettimeofday(&start, NULL);
            ios_base::sync_with_stdio(false);
            recursive_quick_sort(arr_rec, 0, length - 1);
            gettimeofday(&end, NULL);
            ios_base::sync_with_stdio(true);

            recursive_time += (end.tv_usec - start.tv_usec) + (end.tv_sec - start.tv_sec) * 1000000;

            gettimeofday(&start, NULL);
            ios_base::sync_with_stdio(false);
            iterative_quick_sort(arr_iter, length - 1);
            gettimeofday(&end, NULL);
            ios_base::sync_with_stdio(true);

            iterative_time += (end.tv_usec - start.tv_usec) + (end.tv_sec - start.tv_sec) * 1000000;


        }

        cout << setw(10) << length << setw(15) << right << recursive_time / TEST_CASES << setw(15)
            << iterative_time / TEST_CASES << endl;




    }
}

void recursive_quick_sort(int arr[], const int start, const int end) {

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
    recursive_quick_sort(arr, start, i - 1);
    recursive_quick_sort(arr, i + 1, end);

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

void build_array_for_worst(int arr[], const int length) {

    for (int i{0}; i < length; i++) {
        arr[i] = length - i;
    }

}

void build_array_for_average(int arr[], const int length) {

    for (int i{0}; i < length; i++) {
        arr[i] = rand();
    }

}

void copy_array(int arr1[], int arr2[], const int size) {

    for (int i{0}; i < size; i++) {
        arr1[i] = arr2[i];
    }
}