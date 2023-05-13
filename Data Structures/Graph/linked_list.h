#pragma one

#include<iostream>

template<typename T>
class Node {
public:
    // default constructor
    Node() : next{nullptr} {}
    // explicit one argument constructor
    explicit Node(const T& data, Node *next = nullptr) : data{data}, next{next} {}

    T data;
    Node *next;
};

template<typename T>
class LinkedList {

    friend std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list) {

        for (Node<T> *currentNode{list.first}; currentNode != nullptr; currentNode = currentNode->next) {
            out << currentNode->data << " ";
        }
        out << std::endl;
        return out;
    }

public:

    // constructors
    LinkedList() : first{nullptr}, last{nullptr}, length{0} {}
    // explicit constructor
    explicit LinkedList(const T& data) : length{1} {
        // constructor tha takes one parameter as first item of the list
        first = last = new Node<T>(data);
    }

    // destructor;
    ~LinkedList() {
        // call to the function destroy_list
        destroy_list();
    }

    void destroy_list() {

         // storage occupied by the linked list is deallocated
        Node<T> *currentNode{first}, *prevNode{nullptr};
        while (currentNode != nullptr) {
            prevNode = currentNode;
            // advance the currentNode to the next Node
            currentNode = currentNode->next;
            delete prevNode;
        }

    }

    // utility function for linked list
    bool empty() const {
        return first == last == nullptr;
    }

    size_t size() const {
        return length;
    }

    void clear() {
        // delete the list items using a while loop
        // storage occupied by the linked list is deallocated
        Node<T> *currentNode{first}, *prevNode{nullptr};
        while (currentNode != nullptr) {
            prevNode = currentNode;
            // advance the currentNode to the next Node
            currentNode = currentNode->next;
            delete prevNode;
        }

        // set the first and last nodes as null pointers
        first = last = nullptr;
        // set the list size as 0
        length = 0;

    }

    // insert function of the list
    void insert_first(const T& data) {

        Node<T> *node = new Node<T>(data, first);
        if (first == nullptr) {
            first = last = node;
        } else {
            first = node;
        }
        length++;

    }

    void insert_last(const T& data) {

        Node<T> *node = new Node<T>(data);
        if (first == nullptr) {
            first = last = node;
        } else {
            last->next = node;
            last = node;
        }
        length++;

    }

    // delete function 
    bool delete_item(const T& data) {

        if (first == nullptr) {
            return false;
        }

        // first find the node to be deleted
        Node<T> *currentNode{first}, *prevNode{nullptr};
        while (currentNode != nullptr && currentNode->data != data) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        if (currentNode  == nullptr) {
            return false;
        }

        if (currentNode == first) {
            if (currentNode == last) {
                delete currentNode;
                first = last = nullptr;
            } else {

                first = first->next; // setup the new first item
                delete currentNode;
            }
        } else {
            prevNode->next = currentNode->next; // by pass the previous node next node by node next to current node
            if (currentNode == last) {
                last = prevNode; // check whether deleted node is last item and set up the new last  item
            }
            delete currentNode; // delete the current node;
        }
        length--;
        return true;

    }


    Node<T> search(const T& data) const {
        // search for the given data and return the unmodifieable lvalue
        Node<T> *currentNode{first};
        for (; currentNode != nullptr; currentNode = currentNode->next);

        if (currentNode == nullptr) {
            throw std::invalid_argument("no item in the list");
        }
        return *currentNode;

    }

    Node<T>& search(const T& data) {    
        // search for the given data and return modifieable lvalue
        Node<T> *currentNode{first};
        for (; currentNode != nullptr; currentNode = currentNode->next);

        if (currentNode == nullptr) {
            throw std::invalid_argument("no item in the list");
        }
        return *currentNode;

    }

private:
    Node<T> *first, *last;
    size_t length;
};