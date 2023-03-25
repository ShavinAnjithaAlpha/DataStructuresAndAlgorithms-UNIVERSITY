#include<iostream>
#include<ctime>
#include<random>
#include<cstdlib>
#include<sys/time.h>

using namespace std;

void insertion_sort(int array[], const size_t length);
void bubble_sort(int arr[], const size_t length);
void optimized_bubble_sort(int arr[], const size_t length);
void selection_sort(int arr[], const size_t length);

void display_array(const int arr[], const size_t length) {

    for (int i{0}; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void get_array(int array[], size_t length) {

    for (int i{0}; i < length; i++) {
        array[i] = length - i;
    }

}

int main() {

    // srand(time(static_cast<unsigned int>(time(0))));
    struct timeval start, end;

    int lengths[5]{ 500, 1000, 2000, 4000, 8000};

    // sorting functions
    cout << "Insertion sort:" << endl;
    for (int i = 0; i < 5; i++) {
        ios_base::sync_with_stdio(true);
        cout << "total elements in array: " << lengths[i] << endl;

        int array[lengths[i]];
        get_array(array, lengths[i]);

        gettimeofday(&start, NULL);
        ios_base::sync_with_stdio(false);
        insertion_sort(array, lengths[i]);
        gettimeofday(&end, NULL);

        double t = static_cast<double>( (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000000;
        cout << "time taken is: " <<  t << endl;
        cout << endl;
    }
    cout << endl;

    cout << "Bubble sort:" << endl;
    for (int i = 0; i < 5; i++) {
        ios_base::sync_with_stdio(true);
        cout << "total elements in array: " << lengths[i] << endl;

        int array[lengths[i]];
        get_array(array, lengths[i]);

        gettimeofday(&start, NULL);
        ios_base::sync_with_stdio(false);
        bubble_sort(array, lengths[i]);
        gettimeofday(&end, NULL);

        double t = static_cast<double>( (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000000;
        cout << "time taken is: " <<  t << endl;
        cout << endl;
    }
    cout << endl;

    cout << "Optimized bubble sort:" << endl;
    for (int i = 0; i < 5; i++) {
        ios_base::sync_with_stdio(true);
        cout << "total elements in array: " << lengths[i] << endl;

        int array[lengths[i]];
        get_array(array, lengths[i]);

        gettimeofday(&start, NULL);
        ios_base::sync_with_stdio(false);
        optimized_bubble_sort(array, lengths[i]);
        gettimeofday(&end, NULL);

        double t = static_cast<double>( (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000000;
        cout << "time taken is: " <<  t << endl;
        cout << endl;
    }
    cout << endl;

    cout << "Selection sort:" << endl;
    for (int i = 0; i < 5; i++) {
        ios_base::sync_with_stdio(true);
        cout << "total elements in array: " << lengths[i] << endl;

        int array[lengths[i]];
        get_array(array, lengths[i]);

        gettimeofday(&start, NULL);
        ios_base::sync_with_stdio(false);
        selection_sort(array, lengths[i]);
        gettimeofday(&end, NULL);

        double t = static_cast<double>( (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000000;
        cout << "time taken is: " <<  t << endl;
        cout << endl;
    }
    
}

// insertion sort
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

void bubble_sort(int arr[], const size_t length) {

    for (size_t i{length - 1}; i > 0; i--) {
        for (size_t j{0}; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap the items
                int temp{arr[j]};
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }    
        }
    }

}

void optimized_bubble_sort(int arr[], const size_t length) {

    
    for (size_t i{length - 1}; i > 0; i--) {

        bool flag{false};
        for (size_t j{0}; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap the items
                flag = true;
                int temp{arr[j]};
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }    
        }

        if (!flag) {
            return;
        }
    }


}

void selection_sort(int arr[], const size_t length) {

    for (int i{0}; i < length; i++) {
        // find the minimum of the unsorted array
        int min_index{i};
        for (int j{i + 1}; j < length; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // swap the values
        int temp{arr[i]};
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

}