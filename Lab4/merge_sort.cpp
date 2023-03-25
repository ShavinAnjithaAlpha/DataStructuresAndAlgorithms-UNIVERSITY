#include<iostream>
#include<random>
#include<cstdlib>
#include<stdexcept>
#include<sys/time.h>
#include<ctime>

using namespace std;

// functions prototypes
void recursive_merge_sort(int*, int, int);
void iterative_merge_sort(int*, int);
void print_array(const int*, const size_t);
void merge(int*, int, int, int, int);

void build_array(int*, size_t size);

int main() {
    int test_cases{10};

    srand(static_cast<unsigned int>(time(0)));
    struct timeval start, end;

    long lengths[10]{10000, 30000, 50000, 70000, 90000, 110000, 130000, 150000, 180000, 210000};

    cout << "recursive merge sort:" << endl;
    for (long length: lengths) {

        // create an array
        int arr[length];
        // initialize time to 0
        long time{0};
        
        for (int k{0}; k < test_cases; k++) {
            build_array(arr, length);

            gettimeofday(&start, NULL);
            ios_base::sync_with_stdio(false);
            recursive_merge_sort(arr, 0, length - 1);
            gettimeofday(&end, NULL);
            ios_base::sync_with_stdio(true);

            time += (end.tv_usec - start.tv_usec) + 1000000 * (end.tv_sec - start.tv_sec);
        }
        cout << "time taken (" << length << ") : " << time / test_cases << endl;
        
    }

    cout << "iterative merge sort:" << endl;
    for (long length: lengths) {

        // create an array
        int arr[length];
        // initialize time to 0
        long time{0};
        
        for (int k{0}; k < test_cases; k++) {
            build_array(arr, length);

            gettimeofday(&start, NULL);
            ios_base::sync_with_stdio(false);
            iterative_merge_sort(arr, length);
            gettimeofday(&end, NULL);
            ios_base::sync_with_stdio(true);

            time += (end.tv_usec - start.tv_usec) + 1000000 * (end.tv_sec - start.tv_sec);
        }
        cout << "time taken (" << length << ") : " << time / test_cases << endl;
        
    }

    return 0;
}

void iterative_merge_sort(int array[], int size) {

    int length{1};
    while (length < size) {
        int i{0};
        while (i < size) {
            int s1{i}, e1{i + length - 1}, s2{i + length}, e2{i + length * 2 - 1};

            if (s2 > size) {
                break;
            }

            if (e2 > size) {
                e2 = size - 1;
            }

            merge(array, s1, e1, s2, e2);
            i += length * 2;
        }
        length *= 2;
    }

}

void recursive_merge_sort(int array[], int start, int end) {

    if (start >= end) {
        return;
    }

    // calculate the middle of the array
    int middle = (end - start) / 2 + start;
    // merge recusively 
    recursive_merge_sort(array, start, middle);
    recursive_merge_sort(array, middle + 1, end);

    // merging the two sub arrays
    merge(array, start, middle, middle + 1, end);

}

void merge(int array[], int s1, int e1, int s2, int e2) {

    // create two arrays dynamically
    int arr1[e1 - s1 + 1];
    int arr2[e2 - s2 + 1];

    // copying the values
    for (int i{s1}; i <= e1; i++) {
        arr1[i - s1] = array[i];
    }

    for (int j{s2}; j <= e2; j++) {
        arr2[j - s2] = array[j];
    }

    int i{0}, j{0}, k{s1};
    while (i < e1 - s1 + 1 && j < e2 - s2 + 1) {
        if (arr1[i] <= arr2[j]) {
            array[k] = arr1[i];
            i++;
        } else {
            array[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < e1 - s1 + 1) {
        array[k] = arr1[i];
        i++;
        k++;
    }

    while (j < e2 - s2 + 1) {
        array[k] = arr2[j];
        j++;
        k++;
    }

}

void print_array(const int array[], const size_t size) {
    for (size_t i{0}; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void build_array(int array[], size_t size) {

    for (int i{0}; i < size; i++) {
        array[i] = size - i;
    }
}