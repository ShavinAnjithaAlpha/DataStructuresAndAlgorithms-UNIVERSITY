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




}