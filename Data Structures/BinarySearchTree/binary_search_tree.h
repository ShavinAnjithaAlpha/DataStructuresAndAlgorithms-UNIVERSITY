#include<iostream>
#include<stdexcept>
#include<queue>
#include<stack>

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

template<typename T>
class TreeNode {
public:
    TreeNode() : left{nullptr}, right{nullptr} {
        // empty default constructor
    }

    explicit TreeNode(const T& data, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr) 
        : data{data}, left{left}, right{right} {
            // empty body
        }

    T data;
    TreeNode<T> *left, *right;
};

template<typename T>
class BinarySearchTree {
public:
    // constructors
    BinarySearchTree() : root{nullptr} {}; // default constructor;
    // one parameter explicit constrctor
    explicit BinarySearchTree(const T& data) {
        root = new TreeNode<T>(data);
    }

    // insert operation
    void insert(const T& data) {
        
        if (root == nullptr) {
            root = new TreeNode<T>(data);
            return;
        }
        // call to the recursive insert method
        insert(data, root);

    }

    void insert(const T& data, TreeNode<T>* node) {

        // preserved thr BST property
        if (node->data < data) {
            // add the new node recursively based on existance of the right
            if (node->right != nullptr) 
                insert(data, node->right);
            else {
                node->right = new TreeNode<T>(data);
            }
        } else {
            // add the new node recursively based on existance of the left
            if (node->left != nullptr) 
                insert(data, node->left);
            else {
                node->left = new TreeNode<T>(data);
            }
        }
    }

    void iterative_insert(const T& data) {

        TreeNode<T>* newNode = new TreeNode<T>(data);
        TreeNode<T> *currentNode{root}, *prev{nullptr};

        while (currentNode != nullptr) {
            prev = currentNode;

            if (data > currentNode->data) 
                currentNode = currentNode->right;
            else 
                currentNode = currentNode->left;
        }

        // add the new node to prev node based on data
        if (prev == nullptr) {
            root = newNode;
        } else if (prev->data > data) {
            prev->left = newNode;
        } else {
            prev->right = newNode;
        }
        

    }

    // delete operation
    bool delete_node(const T& data) {

        // first find the node which we need to delete
        TreeNode<T> *currentNode{root}, *parent{nullptr};
        while (currentNode != nullptr && currentNode->data != data) {
            parent = currentNode;
            if (currentNode->data < data) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
        }

        // check whether node which we need to delete is exists
        if (currentNode == nullptr) {
            return false;
        } else {

            // there are four cases to consider
            // first case -- node has no left or right child -- simply delete it and unplug it from tree
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                replant(currentNode, parent, nullptr);
            } else if (currentNode->left == nullptr) {
                replant(currentNode, parent, currentNode->right);
            } else if (currentNode->right == nullptr) {
                replant(currentNode, parent, currentNode->left);
            } else {
                
                // first find the successor of the right sub tree
                TreeNode<T> *succ{currentNode->right}, *succParent{nullptr};
                while (succ->left != nullptr) {
                    succParent = succ;
                    succ = succ->left;
                }
                // there is two cases we need consider
                if (succ == currentNode->right) {
                    currentNode->data = succ->data; // replace the successor and current
                    currentNode->right = succ->right;
                    delete succ;
                } else {
                    T temp = succ->data;
                    replant(succ, succParent, succ->right);
                    currentNode->data = temp; // replace the successor value with deleted node value
                }
            }
            return true;

        }

    }

    // search functions
    const TreeNode<T>* const recursive_search(const T& data) const {

        return recursive_search_helper(data, root);

    }

    const TreeNode<T>* const iterative_search(const T& data) const {

        TreeNode<T>* currentNode{root};
        while (currentNode != nullptr && currentNode->data != data) {
            if (data > currentNode->data) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
        }

        return currentNode;

    }

    // maximum and minimum methods
    T minimum() const {

        TreeNode<T>* currentNode{root};
        while (currentNode->left != nullptr) {
            currentNode = currentNode->left;
        }

        if (currentNode == nullptr)
            throw std::length_error("tree is empty");
        return currentNode->data;
    }

    T maximum() const {

        TreeNode<T>* currentNode{root};
        while (currentNode->right != nullptr) {
            currentNode = currentNode->right;
        }

        if (currentNode == nullptr)
            throw std::length_error("tree is empty");
        return currentNode->data;
    }

    // tree traversal methods
    void inorder_traversal(const TreeNode<T>* node) const {
        
        if (node != nullptr) {
            inorder_traversal(node->left);
            std::cout << node->data << " ";
            inorder_traversal(node->right);
        }

    }

    void preorder_traversal(const TreeNode<T>* node) const {
        
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorder_traversal(node->left);
            preorder_traversal(node->right);
        }
    }

    void postorder_traversal(const TreeNode<T>* node) const {

        if (node != nullptr) {
            postorder_traversal(node->left);
            postorder_traversal(node->right);
            std::cout << node->data << " ";
        }
    }

    void itertaive_preorder_traversal() const {

        if (root != nullptr) {
            std::stack<TreeNode<T>*> travStack;
            travStack.push(root);

            while (!travStack.empty()) {
                TreeNode<T>* node = travStack.top();
                travStack.pop();
                std::cout << node->data << " ";

                if (node->right != nullptr) travStack.push(node->right);
                if (node->left != nullptr) travStack.push(node->left);
            }
            std::cout << std::endl;
        }

    }

    void iterative_postorder_traversal() const {

        if (root != nullptr) {
            std::stack<TreeNode<T>*> runtimeStack;
            std::stack<TreeNode<T>*> reverseStack;

            runtimeStack.push(root);
            while (!runtimeStack.empty()) {
                TreeNode<T>* node = runtimeStack.top();
                reverseStack.push(node);
                runtimeStack.pop();

                if (node->left != nullptr) runtimeStack.push(node->left);
                if (node->right != nullptr) runtimeStack.push(node->right);
            }

            // print the reverse stack until stack is empty
            while (!reverseStack.empty()) {
                std::cout << reverseStack.top()->data << " ";
                reverseStack.pop();
            }
            std::cout << std::endl;
        }

    }

    void breadthFirst() const {

        std::queue<TreeNode<T>*> queue;
        if (root != nullptr) {
            queue.push(root);
            while (!queue.empty()) 
            {
                // take the value from the queue first element
                TreeNode<T>* temp = queue.front();
                queue.pop();
                // add the left and right nodes to the queue
                if (temp->left != nullptr) queue.push(temp->left);
                if (temp->right != nullptr) queue.push(temp->right);
                std::cout << temp->data << " ";
            }
            std::cout << std::endl;
            
        }

    }

    const TreeNode<T>* const getRoot() const {
        return root;
    }

    bool is_empty() const {
        return root == nullptr;
    }

private:
    // helper method for recursive search
    const TreeNode<T>* const recursive_search_helper(const T& data, TreeNode<T>* node) const {

        if (node == nullptr || node->data == data) 
            return node;
        else if (node->data < data) {
            return recursive_search_helper(data, node->right);
        } else {
            return recursive_search_helper(data, node->left);
        }

    }
    // rebraching the tree
    void replant(TreeNode<T>* current, TreeNode<T>* parent, TreeNode<T>* child) {

        if (parent == nullptr) {
            root = child;
        } else if (current == parent->left) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete current;
    }


    TreeNode<T>* root;

};

#endif