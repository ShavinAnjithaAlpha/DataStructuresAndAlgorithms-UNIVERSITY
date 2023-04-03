#include<iostream>
#include<string>
#include<stdexcept>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// class for holds the data and pointers
template<typename T>
class Node {
public:

    Node() : next{nullptr} {
        // defualt constructor
    }

    explicit Node(const T& value, Node<T>* const next = nullptr) : value(value) , next{next} {
        // explicit constructor
    }

    T value;
    Node<T> *next;

};

template<typename T>
class LinkedList {
    // insert the list into output stream
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list) {

        Node<T>* currentPtr{list.head};
        for (; currentPtr != nullptr; currentPtr = currentPtr->next) {
            out << currentPtr->value << " ";
        }
        out << std::endl;
        return out;
    }

    // get one element from the input stream // work only for primary value types
    friend std::istream& operator>>(std::istream& in, LinkedList<T>& list) {

        T temp;
        in >> temp;
        list.push_back(temp);

        return in;

    }

public:
    // constructors
    // default constructor
    LinkedList() : head{nullptr}, tail{nullptr}, size{0} {
        // empty body
    } 

    // exlplicit constructor
    explicit LinkedList(const T& data) : size{1} {
        head = tail = new Node<T>(data);
    }

    // destructors
    ~LinkedList() {

        Node<T>* current = head, *temp = head;
        while (current != nullptr) {
            temp = current;
            current = current->next;
            delete temp;
        }

    }

    // basic operations 
    // modyfying operations
    // add new element to the back of the list
    void push_back(const T& data) {

        Node<T>* newNode{new Node<T>(data)};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    // add new element to the front of the list
    void push_front(const T& data) {

        if (head == nullptr) {
            head = tail = new Node<T>(data);
        } else {
            Node<T>* newNode{new Node<T>(data, head)};
            head = newNode;
        }
        size++;

    }
    // insert new element to the given position
    bool insert(const T& data, int position) {

        if (position > size) {
            return false;
        }

        Node<T>* currentPtr{head};
        for (int i{0}; i < position - 1; i++) {
            currentPtr = currentPtr->next;
        }
        
        if (currentPtr->next != nullptr) {
            currentPtr->next = new Node<T>(data, currentPtr->next->next);
            delete currentPtr->next;
        } else {
            currentPtr->next = new Node<T>(data);
        }
        return true;

    }

    bool delete_back() {

        if (tail == nullptr) return false;
        
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node<T>* currentPtr{head};
            for (; currentPtr->next != tail; currentPtr = currentPtr->next); // find the element prevoius to the tail
            delete tail; // delete the tail node
            tail = currentPtr; // set the new tail
            tail->next = nullptr; // set as the last element

        }
        size--;
        return true;


    }

    bool delete_front() {

        if (head == nullptr) {
            return false;
        }

        Node<T>* deletedNode{head};
        if (head == tail) {
            head = tail = nullptr;
        } else {
            Node<T>* tmp{deletedNode->next};
            head = tmp;
        }
        delete deletedNode;
        size--;
        return true;

    }

    bool delete_item(const T data) {

        if (head == nullptr) return false;

        if (head == tail && head->value == data) {
            delete head;
            head = tail = nullptr;
            size--;
            return true;
        } else {
            Node<T>* currentPtr{head}, *prevPtr{head};
            while (currentPtr->next != nullptr) {
                if (currentPtr->value == data) {
                    // delete the node
                    prevPtr->next = currentPtr->next;
                    if (currentPtr == tail) {
                        tail = prevPtr; // set the new tail if deleted node is tail
                    } else if (currentPtr == head) {
                        head = currentPtr->next; // set new head if deleted node is head
                    }
                    delete currentPtr;
                    size--;
                    return true;
                }
                prevPtr = currentPtr;
                currentPtr = currentPtr->next;
            }
        }

        return false;

    }

    bool is_empty() const {
        return head == nullptr;
    }
    size_t length() const {
        return size;
    }

    // query operations
    T& operator[](int index) {

        if (index > size - 1) {
            throw std::invalid_argument("list index out of bounds");
        }

        Node<T>* currentPtr{head};
        for (int i{0}; i < index; i++, currentPtr = currentPtr->next); // traverse through the list
        return currentPtr->value;

    }

    int search(const T& data) const {
        // return -1 if item is not found
        if (head == nullptr) return -1;

        Node<T>* currentPtr{head};
        for (int i{0}; currentPtr != nullptr; currentPtr = currentPtr->next, i++) {
            if (currentPtr->value == data) {
                return i;
            }
        }
        return -1;

    }

    void print_list() const {

        if (head == nullptr) {
            std::cout << "Empty List" << std::endl;
        }

        for (Node<T>* currentPtr{head}; currentPtr != nullptr; currentPtr = currentPtr->next) {
            std::cout << currentPtr->value << " ";
        }
        std::cout << std::endl;

    }

private:
    Node<T> *head, *tail;
    size_t size = 0;

};

#endif