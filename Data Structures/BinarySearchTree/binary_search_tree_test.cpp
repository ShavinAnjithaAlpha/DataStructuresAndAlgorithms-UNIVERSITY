#include<iostream>
#include"binary_search_tree.h"

using namespace std;

int main() {

    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(4);
    tree.insert(12);
    tree.insert(8);
    tree.insert(15);
    tree.insert(0);
    tree.insert(1);
    tree.insert(11);
    

    cout << "inorder traversal of tree: ";
    tree.inorder_traversal(tree.getRoot());
    cout << endl;

    cout << "preorder traversal of tree: ";
    tree.preorder_traversal(tree.getRoot());
    cout << endl;

    cout << "postorder traversal of tree: ";
    tree.postorder_traversal(tree.getRoot());
    cout << endl;



}