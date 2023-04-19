#include<iostream>
#include<cmath>

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
        size++;
    }

    void inorderTraversal() const {
        inorderTraversalHelper(root);
        std::cout << std::endl;
    }

    void preorderTraversal() const {
        preorderTraversalHelper(root);
        std::cout << std::endl;
    }

    void balance() {
        // first make the backbone
        make_backbone();
        // get the perfect nodes count
        int perfect_node_count = perfect_count();
        int extra = static_cast<int>(size) - perfect_node_count;

        // left rotate series for extra nodes
        Node<T> *tmp{root}, *gr{nullptr};
        for (int i{0}; i < extra; i++) {
            gr = left_rotate(tmp, tmp->right, gr);
            tmp = gr->right;
        }

        // left rotate series for perfect nodes
        int x = perfect_node_count / 2;
        while (x > 0) {
            tmp = root, gr = nullptr;
            for (int i{0}; i < x; i++) {
                gr = left_rotate(tmp, tmp->right, gr);
                tmp = gr->right;
            }
            x /= 2;
        }


    }

private:

    // method for count the
    int perfect_count() const {

        int perfect_count{0}, i{0};
        while (perfect_count < size) {
            i++;
            perfect_count = std::pow(2, i) - 1;
        }

        return std::pow(2, i - 1) - 1;

    }

    // method for make the backbone of the tree
    void make_backbone() {

        Node<T> *tmp{root}, *gr{nullptr};
        while (tmp != nullptr) {
            if (tmp->left == nullptr) {
                gr = tmp;
                tmp = tmp->right;
            }
            else {
                tmp = right_rotate(tmp, tmp->left, gr);
            }
        }

    }

    // create left rotations and right rotations
    Node<T>* left_rotate(Node<T>* parent, Node<T>* child, Node<T>* grand) {
        if (root == parent) {
            root = child; // set the new root
        } else {
            if (grand->left == parent) grand->left = child;
            else grand->right = child;
        }

        Node<T>* temp{child->left};
        child->left = parent;
        parent->right = temp;

        return child;
    }

    Node<T>* right_rotate(Node<T>* parent, Node<T>* child, Node<T>* grand) {
        if (parent == root) {
            root = child; // set the new root
        } else {
            if (grand->left == parent) grand->left = child;
            else grand->right = child;
        }

        Node<T>* temp{child->right};
        child->right = parent;
        parent->left = temp;

        return child;
    }

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

    void preorderTraversalHelper(Node<T>* node) const {

        if (node == nullptr) return;

        std::cout << node->data << " ";
        preorderTraversalHelper(node->left);
        preorderTraversalHelper(node->right);
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