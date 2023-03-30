#include<iostream>
#include<iomanip>

using namespace std;

void insert_element(int*, const int, const int); // function protype for add an element
void print_array(const int*, const size_t);

int main() {

    int size{0};
    cout << "size of the stream of integers: ";
    cin >> size; 
    // create a dynamic array of provided size
    int* arr = new int[size];

    int element{0};
    double median;

    cout << endl;
    for (int i{0}; i < size; i++) {
        cout << "\nEnter " << (i + 1) << "th element: ";
        cin >> element;

        insert_element(arr, element, i);
        // get the median
        if (i % 2 == 0) {
            median = arr[i / 2];
        } else {
            median = static_cast<double>((arr[i / 2] + arr[i / 2 + 1])) / 2.0;
        }

        cout << endl;
        cout << "sorted array: ";
        print_array(arr, i + 1);
        cout << "median: " << setprecision(1) << fixed << median << endl;
    }

}

void insert_element(int arr[], const int element, const int size) {

    int i{size - 1};
    while (i >= 0 && element < arr[i]) {
        arr[i + 1] = arr[i];
        i--;
    }
    // insert the element in the sorted way
    arr[i + 1] = element;

}

void print_array(const int arr[], const size_t size) {

    cout << "[";
    for (int i{0}; i < size - 1; i++) {
        cout << arr[i] << ", ";
    }

    cout << arr[size - 1] << "]" << endl;

}