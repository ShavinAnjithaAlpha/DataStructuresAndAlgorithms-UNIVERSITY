#include<iostream>

#ifndef DSW_BST_TREE_H
#define DSW_BST_TREE_H

template<typename T>
class Node {
public:

    Node() : left{nullptr}, right{nullptr} {} // default constructor
    explicit Node(const T& data, Node<T>* left = nullptr, Node<T>* right = nullptr)
        : left{left}, right{right}, data{data} {
            // empty body
        }

    T data;
    Node<T> *left, *right;

};

template<typename T>
class DSWBinarySearchTree {
public:    
    // default constructor
    DSWBinarySearchTree() : root{nullptr}, size{0} {
        // empty body
    }
    // explciti one parameter constructor
    explicit DSWBinarySearchTree(const T& data) : size{1}, root{new Node<T>(data)} {
        // empty body
    }

    // destrcutor
    ~DSWBinarySearchTree() {
        destructorHelper(root);
    }

    void insert(const T& data) {
        if (root == nullptr) {
            root = new Node<T>(data);
        } else {
            insertHelper(root, data);
        }
    }

    void inorderTraversal() const {
        inorderTraversalHelper(root);
    }


private:

    // helper methods
    void destructorHelper(Node<T>* node) {
        if (node == nullptr) return;

        // store the pointers to right and left nodes
        Node<T>* left = node->left;
        Node<T>* right = node->right;
        delete node;
        
        // delete the right and left branches
        destructorHelper(left);
        destructorHelper(right);

    }

    void inorderTraversalHelper(Node<T>* node) const {
        if (node == nullptr) return;

        inorderTraversalHelper(node->left);
        std::cout << node->data << " ";
        inorderTraversalHelper(node->right);
    }

    void insertHelper(Node<T>* node, const T& data) {

        if (data > node->data) {
            if (node->right != nullptr) insertHelper(node->right, data);
            else node->right = new Node<T>(data);
        } else {
            if (node->left != nullptr) insertHelper(node->left, data);
            else node->left = new Node<T>(data);
        }
    }

    Node<T>* root;
    size_t size;
};

#endif