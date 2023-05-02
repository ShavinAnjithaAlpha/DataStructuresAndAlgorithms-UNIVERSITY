#include<iostream>
#include<stdexcept>

#include "max_priority_queue.h"

using namespace std;

int main() {

    MaxPriorityQueue<int> queue;
    // insert some values into the queue
    queue.insert(5);
    queue.insert(8);
    queue.insert(4);
    queue.insert(9);
    queue.insert(6);
    cout << "queue after insertions : " << queue;
    cout << "\nqueue extract : " << queue.extract_maximum() << endl;
    cout << "queue extract : " << queue.extract_maximum() << endl;
    cout << "queue after dequeue : " << queue;

    queue.insert(104);
    queue.insert(2);
    queue.insert(3);
    queue.insert(12);
    cout << "\nqueue after insertion again : " << queue;
    cout << "\nqueue extract : " << queue.extract_maximum() << endl;
    cout << "queue extract : " << queue.extract_maximum() << endl;
    cout << "queue after dequeue : " << queue;

}