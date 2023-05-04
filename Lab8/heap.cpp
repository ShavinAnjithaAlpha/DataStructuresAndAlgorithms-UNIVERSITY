#include <iostream>
using namespace std;
  
inline int LEFT(int i) {
   return 2 * i;
}

inline int RIGHT(int i) {
   return 2 * i + 1;
}

inline int PARENT(int i) {
   return i / 2;
}

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   // fetch the left and right index of the root index
   int left = LEFT(root), right = RIGHT(root), largest;
   // check whether left exist and its value is larger than the root value
   if (left <= n && arr[root - 1] < arr[left - 1]) {
      largest = left;
   } else {
      largest = root;
   }

   // check whether right index exist in the hepa and its value is larger than the largest value
   if (right <= n && arr[largest - 1] < arr[right - 1]) {
      largest = right;
   }

   // swap the largest and root values id the root is different fromt he largest
   if (root != largest) {
      // swap the values
      int tmp{*(arr + largest - 1)};
      *(arr + largest - 1) = *(arr + root - 1);
      *(arr + root - 1) = tmp;
      // recursively call to the heapify to heapify the sub tree which changed
      heapify(arr, n, largest);
   }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2; i > 0; i--) {
      heapify(arr, n, i); // heapify the sub tree which root index is i
   }
  
   // extracting elements from heap one by one
   for (int i{n}; i > 1; i--) {
      // swap the first and last element of the heap
      int tmp{*(arr + i - 1)};
      *(arr + i - 1) = *arr;
      *arr = tmp;
      // decrease the heap size by 1
      n--;
      // heapify the root of the heap again
      heapify(arr, n, 1);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int n{0};
   cout << "Enter array length : ";
   cin >> n;
   int* heap_arr = new int[n];

   cout << "Enter array : ";
   for (int i{0}; i < n; i++) {
      cin >> heap_arr[i];
   }

   // int heap_arr[] = {4,17,3,12,9,6};
   // int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}