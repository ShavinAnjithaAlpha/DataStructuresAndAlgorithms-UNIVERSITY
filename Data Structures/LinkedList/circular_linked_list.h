#include<iostream>
#include<stdexcept>

#ifndef CIRCULAR_LINKEDLIST_H
#define CIRCULAR_LINKED_LIST_H

template<typename T>
class Node {
public:
    // default constructor
    Node() : prev{nullptr}, next{nullptr} {}
    // explicit constructor
    explicit Node(const T& data, Node<T>* prev = nullptr, Node<T>* next = nullptr) :
        data{data}, next{next}, prev{prev} {
            // empty body
        } 
    // fields
    T data;
    Node<T> *prev, *next;

};

template<typename T>
class CircularLinkedList {

    friend std::ostream& operator <<(std::ostream& out, const CircularLinkedList& list) const {

        Node<T>* currentNode{list->head};
        while (currentNode != nullptr) {
            out << currentNode->data << " "; 
        }
        std::cout << std::endl;

    }

public:
    CircularLinkedList() : size{0}, head{nullptr} {} // default constructor
    // explicit constructor
    explicit CircularLinkedList(const T& data) : head{new Node<T>(data)}, size{1} {
        // empty body
    }
    // destructor
    ~CircularLinkedList() {

        Node<T> *currentPtr{head}, *prev{nullptr};
        while (currentPtr != nullptr) {
            prev = currentPtr;
            currentPtr = currentPtr->next;
            delete prev;

            std::cout << "delete " << prev->data << std::endl;
        }
    }

    // modifying methods
    void push_back(const T& data) {

        if (head == nullptr) head = new Node<T>(data);
        else {

            if (size == 1) {
                head->next = new Node<T>(data, head, head);
                head->prev = head->next;
            } else {
                // get the list tail by heda->prev
                Node<T>* tailNode{head->prev};
                tailNode->next = new Node<T>(data, tailNode, head);
                head->prev = tailNode->next;
            }

        }
        size++;

    }

    void push_front(const T& data) {

        if (head == nullptr) head = new Node<T>(data);
        else {

            if (size == 1) {
                head->prev = new Node<T>(data, head, head);
                head->next = head->prev;
                head = head->prev;
            } else {
                Node<T>* newNode = new Node<T>(data, head->prev, head); // create a new node
                Node<T>* tailNode = head->prev; // fetch the tail
                head->prev = newNode; // set the new pointers
                tailNode->next = newNode;
                head = newNode;
            }

        }
        size++;
    }

    T delete_back() {

        if (head == nullptr) {
            throw std::length_error("list is empty");
        }

        T data;
        if (size == 1) {
            data = head->data; // copy the deleted data
            delete head;
            head = nullptr;
        } else {
            data = head->prev->data;
            Node<T>* deletedNode{head->prev}; // fetch the deleted node-tail
            // set the pointers for new tail
            head->prev = deletedNode->prev;
            deletedNode->next = head;
            delete deletedNode;
        }

        size--;
        return data;
    }

    T delete_front() {

        if (head == nullptr) {
            throw std::length_error("list is empty");
        }

        T data;
        if (size == 1) {
            data = head->data;
            delete head;
            head = nullptr;
        } else {

            Node<T>* tailNode{head->prev};
            tailNode->next = head->next;
            head->next->prev = tailNode;
            delete head;
            head = tailNode->next;
        }
        size--;
        return data;
    }

    // querying methods
    T operator [](unsigned int index) const {
        
        if (index > size - 1) {
            throw std::out_of_range("list is out of range");
        }

        Node<T>* node{head};
        for (unsigned int i{0}; i < index; i++, node = node->next);
        return node->data;
        
    }

    T& operator [](unsigned int index) {
        if (index > size - 1) {
            throw std::out_of_range("list is out of range");
        }

        Node<T>* node{head};
        for (unsigned int i{0}; i < index; i++, node = node->next);
        return node->data;
    }

    size_t length() const {
        return size;
    }

    bool empty() const {
        return head == nullptr;
    }

private:
    size_t size;
    Node<T>* head;
};

#endif