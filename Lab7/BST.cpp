#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {

    if (root != nullptr) {
        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    cout << "enter";
    if (node == nullptr) {
        struct node *newNode;
        *newNode = {.key = key, .left = nullptr, .right = nullptr};
        return newNode;
    }
    cout << "root pass";
    if (key > node->key) {
        // insert the new node recursively based on the existance of the right
        if (node->right != nullptr) 
            return insertNode(node->right, key);
        else {
            struct node *newNode;
            *newNode = {.key = key, .left = nullptr, .right = nullptr};
            node->right = newNode;
            return node;
        }
    } else {
        cout << "left";
        // insert the new node recursively based on the existance of the left
        if (node->left != nullptr) 
            return insertNode(node->left, key);
        else {
            cout << "insert";
            struct node *newNode;
            *newNode = {.key = key, .left = nullptr, .right = nullptr};
            node->left = newNode;
            return node;
        }
    }

    return node;


}

// rebraching the tree
void replant(struct node* root, struct node* current, struct node* parent, struct node* child) {

    if (parent == nullptr) {
        root = child;
    } else if (current == parent->left) {
        parent->left = child;
    } else {
        parent->right = child;
    }
    delete current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {

    // find the node which needed to be deleted
    struct node *currentNode{root}, *prevNode{nullptr};
    
    while (currentNode->key != key && currentNode != nullptr) {
        prevNode = currentNode;
        if (key > currentNode->key) {
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }

    }

    // check whether there are key to be deleted
    if (currentNode != nullptr) {

        if (currentNode->left == nullptr && currentNode->right == nullptr) {

        }

    }

    return root;

}



// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        cout << operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}