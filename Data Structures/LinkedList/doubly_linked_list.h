#include<iostream>
#include<stdexcept>

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H


template<typename T>
class Node {
public:

    Node() : next{nullptr}, prev{nullptr} {
        // empty constructor
    }

    explicit Node(const T& value, Node<T>* next = nullptr, Node<T>* prev = nullptr) : 
        value{value}, next{next}, prev{prev} {
            // empty body constructor
        }

    T value;
    Node<T> *next, *prev; 
};

template<typename T>
class DoubleLinkedList {

    friend std::ostream& operator<<(std::ostream& out, const DoubleLinkedList<T>& list) {

        Node<T>* currentPtr{list.head};
        for (; currentPtr != nullptr; currentPtr = currentPtr->next) {
            out << currentPtr->value << " "; 
        }
        out << std::endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, DoubleLinkedList<T>& list) {

        T temp;
        in >> temp;
        list.push_back(temp);
        return in;

    }

public:
    // default constructor;
    DoubleLinkedList() : size{0}, head{nullptr}, tail{nullptr} {
        // empty constcutor;
    }

    explicit DoubleLinkedList(const T& value) : size{1} {
        // set the value as the head and tail
        head = tail = new Node<T>(value);
    }

    // destructor
    ~DoubleLinkedList() {

        Node<T>* currentPtr{head}, *temp{head};
        while (currentPtr != nullptr) { // delete nodes one by one
            temp = currentPtr;
            currentPtr = currentPtr->next;
            delete temp;
        }

    }

    // modyfying operations
    void push_back(const T& data) {
        
        if (head == nullptr) {
            head = tail = new Node<T>(data);
        } else {
            Node<T>* node = new Node<T>(data, nullptr, tail);
            tail->next = node;
            tail = node;
        }
        size++;
        
    }

    void push_front(const T& data) {

        if (head == nullptr) {
            head = tail = new Node<T>(data);
        } else {
            Node<T>* node = new Node<T>(data, head, nullptr);
            head->prev = node;
            head = node;
        }       
        size++;
    }

    bool delete_back() {

        if (head == nullptr) {
            return false;
        }

        if (tail == head) { // if one element in the list
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* temp{tail->prev};
            temp->next = nullptr; // set the pointers to null values
            delete tail;
            tail = temp; // set the new tail
        }
        size--;
        return true;

    }

    bool delete_front() {

        if (head == nullptr) {
            return false;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* temp{head->next};
            temp->prev = nullptr; // set the pointers to null values 
            delete head;
            head = temp; // set the new head
        }
        size--;
        return true;

    }

    void insert(const T& data, const unsigned int position) {

        if (position > size - 1) {
            throw std::invalid_argument("cannot insert to the position " + position);
        }

        Node<T>* currentPtr{head};
        for (unsigned int i{0}; i < position - 1; i++, currentPtr = currentPtr->next);
        
        if (position == 0) {
            Node<T>* node = new Node<T>(data, head, nullptr);
            head->prev = node;
            head = node;
        } else {
            Node<T> *tmp{currentPtr->next};
            currentPtr->next = new Node<T>(data, tmp, currentPtr); // insert the element to the new position
            tmp->prev = currentPtr->next; // set the pointers
        }
        size++;

    }

    bool delete_element(const T& data) {

        if (head == nullptr) return false;

        Node<T>* currentPtr{head};
        while (currentPtr != nullptr) {
            if (currentPtr->value == data) {
                // check for coundry conditions
                if (currentPtr == head && currentPtr == tail) {
                    delete head; // delete head if only one item is in the list
                    head = tail = nullptr;
                } else {
                    if (currentPtr == head) {
                        Node<T>* tmp{head->next};
                        tmp->prev = nullptr;
                        head = tmp;
                    } else if (currentPtr == tail) {
                        Node<T>* tmp{tail->prev};
                        tmp->next = nullptr;
                        tail = tmp;
                    } else {
                        Node<T> *p{currentPtr->prev}, *n{currentPtr->next};
                        p->next = n;
                        n->prev = p;
                    }
                    delete currentPtr;
                }
                size--;
                return true;
            }
            currentPtr = currentPtr->next;
        }
        return false;

    }

    T& operator[](unsigned int index) {
        
        if (index > size - 1) { // throw exception if index is not valid
            throw std::invalid_argument("list index out of bound exception");
        }

        Node<T>* currentPtr{head};
        for (unsigned int i{0}; i < index; i++, currentPtr = currentPtr->next); // traverse until find the correct index
        return currentPtr->value;

    }

    T operator [](unsigned int index) const {

        if (index > size - 1) {
            throw std::invalid_argument("list index out of bound exception");
        }

        Node<T>* currentPtr{head};
        for (unsigned int i{0}; i < index; i++, currentPtr = currentPtr->next); // traverse until find the correct index
        return currentPtr->value;

    }

    size_t length() const {
        return size;
    }

    bool is_empty() const {
        return head == nullptr;
    }

    void print_list() const {

        Node<T>* currentPtr{head};
        for (; currentPtr != nullptr; currentPtr = currentPtr->next) {
            std::cout << currentPtr->value << " ";
        }
        std::cout << std::endl;

    }

private:

    size_t size = 0;
    Node<T> *head, *tail;

};

#endif