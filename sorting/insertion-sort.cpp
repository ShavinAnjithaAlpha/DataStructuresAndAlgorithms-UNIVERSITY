#include <iostream>

using namespace std;

void insertion_sort(int array[], const size_t length); // insertion sort funtion prototype
void print_array(const int array[], const size_t length);

int main(){

    const size_t LENGTH{10};

    int array[LENGTH] {55, -22, -9, 7, 1, -45, 2, 0, 8, -1};
    print_array(array, LENGTH); // print the array before sorting

    insertion_sort(array, LENGTH);

    print_array(array, LENGTH); // print the array after the sorting

    return 0;
}

void insertion_sort(int array[], const size_t length) {

    for (int i{1}; i < length; i++) {
        int current_item{array[i]};

        int j{i - 1};
        while (j >= 0 && current_item < array[j]) {
            array[j + 1] = array[j];
            j--;
        }

            // replace the current item value
        array[j + 1] = current_item;

    }

}

void print_array(const int array[], const size_t length) {
    for (unsigned int i{0}; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}