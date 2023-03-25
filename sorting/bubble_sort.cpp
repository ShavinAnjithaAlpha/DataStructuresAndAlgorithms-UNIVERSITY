#include<iostream>
#define SIZE 10;

using namespace std;

void bubble_sort(int array[], const size_t length);
void print_array(const int* arr, const size_t length);

int main() {

    int arr[5] {7, 5, 9, 6, 4};
    print_array(arr, 5);
    bubble_sort(arr, 5);
    print_array(arr, 5);


    return 0;
}

void bubble_sort(int arr[], const size_t length) {

    for (size_t i{length - 1}; i > 0; i--) {
        for (size_t j{0}; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap the values
                int temp{arr[j]};
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }    
        }
    }

}

void print_array(const int* arr, const size_t length) {

    for (size_t i{0}; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}