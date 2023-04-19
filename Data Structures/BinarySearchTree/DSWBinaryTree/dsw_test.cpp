#include<iostream>
#include "dsw_binary_search_tree.h"

using namespace std;

int main() {
    
    DSWBinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(8);
    tree.insert(0);
    tree.insert(6);
    tree.insert(11);
    tree.insert(3);
    tree.insert(7);

    cout << "tree in inorder: ";
    tree.inorderTraversal();

    cout << "\ntree in preorder: ";
    tree.preorderTraversal();
    // balanced the tree
    tree.balance();
    cout << "\ntree after balancing (preorder traversal) : ";
    tree.preorderTraversal();

}