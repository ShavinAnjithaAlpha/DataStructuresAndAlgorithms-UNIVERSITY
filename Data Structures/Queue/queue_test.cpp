#include<iostream>
#include<stdexcept>

#include"queue.h"

using namespace std;

int main() {

    Queue<int, 5> queue;
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(8);
    queue.enqueue(6);

    cout << "queue after insertion : " << queue;

    cout << "frist element : " << queue.dequeue() << endl;
    cout << "second element : " << queue.dequeue() << endl;
    cout << "frist element : " << queue.dequeue() << endl;

    queue.enqueue(55);
    queue.enqueue(88);
    queue.enqueue(66);

    cout << "queue after enquq and dequq : " << queue;

    cout << "\nTest for Linked Queue : " << endl;
    // create linked queue
    LinkedQueue<int> linked_queue;
    linked_queue.enqueue(4);
    linked_queue.enqueue(7);
    linked_queue.enqueue(1);

    cout << "linked queue after some insertion : " << linked_queue;
    cout << "top of the queue : " << linked_queue.first() << endl;
    linked_queue.dequeue();
    linked_queue.dequeue();

    cout << "linked queue after some dequeues : " << linked_queue;




}