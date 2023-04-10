#include<iostream>
#include"binary_search_tree.h"

using namespace std;

int main() {

    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(4);
    tree.insert(8);
    tree.insert(9);
    tree.insert(11);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    

    cout << "inorder traversal of tree: ";
    tree.inorder_traversal(tree.getRoot());
    cout << endl;

    cout << "preorder traversal of tree: ";
    tree.preorder_traversal(tree.getRoot());
    cout << endl;

    cout << "postorder traversal of tree: ";
    tree.postorder_traversal(tree.getRoot());
    cout << endl;

    cout << "\nMaximum : " << tree.maximum() << endl;
    cout << "Minimum : " << tree.minimum() << endl;

    cout << "\nSearch for 10 : " << tree.recursive_search(10) << endl;
    cout << "Search for 8 : " << tree.recursive_search(8) << endl;
    cout << "Search for 11 : " << tree.iterative_search(11) << endl;
    cout << "Search for 45 : " << tree.iterative_search(45) << endl;

    cout << "\ndelete element 78 : " << tree.delete_node(78) << endl;
    cout << "\ndelete element 15 : " << tree.delete_node(15) << endl;
    cout << "tree after delete : ";
    tree.inorder_traversal(tree.getRoot());
    cout << endl;

    cout << "\ndelete element 8 : " << tree.delete_node(7) << endl;
    tree.delete_node(5);
    cout << "tree after delete: ";
    tree.inorder_traversal(tree.getRoot());
    cout << endl;

    cout << "\nBredth first traversal : ";
    tree.breadthFirst();

    cout << "\nIterative pre order traversal : ";
    tree.itertaive_preorder_traversal();

    cout << "\nIterative post order traversal : ";
    tree.iterative_postorder_traversal();


}