#include<iostream>

using namespace std;

void display(int arr[]) {
    cout << "function size: " << arr << endl;
}

int main() {

    int array[5]{1, 2, 3, 4, 5};
    int* arrPtr{&array[2]};
    arrPtr++;
    cout << "pointer size: " << sizeof(arrPtr) << endl;

    cout << "size of array: " << sizeof(array) << " , " << sizeof(int) << endl;

    for (int i = 0; i < 5; i++){
        cout << array[i] << " ";
    }

    display(array);


}