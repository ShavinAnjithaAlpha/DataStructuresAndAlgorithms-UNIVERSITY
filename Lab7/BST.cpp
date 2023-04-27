#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {

    if (root != nullptr) {
        traverseInOrder(root->left); // goto the left sub tree recursively
        cout << root->key << " "; // print the node value
        traverseInOrder(root->right); // go to the right sub tree recursively
    }

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    
    if (node == nullptr) {
      // set the leaf and root node;
      struct node *newNode = new struct node();
      newNode->key = key;
      return newNode;
    }

    // insert nodes to the left or right recursively based on current node's key value
    if (key > node->key) {
        node->right = insertNode(node->right, key);
    } else {
        node->left = insertNode(node->left, key);
    }

    return node;

}

// rebranching the tree
void replant(struct node* root, struct node* current, struct node* parent, struct node* child) {

    // restructured the tree branch
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
    struct node *currentNode{root}, *parent{nullptr};
    
    while (currentNode->key != key && currentNode != nullptr) {
        parent = currentNode;
        if (key > currentNode->key) {
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }

    }

    // check whether there is a key to be deleted
    if (currentNode != nullptr) {

        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            replant(root, currentNode, parent, nullptr);
        } else if (currentNode->left == nullptr) {
            replant(root, currentNode, parent, currentNode->right);
        } else if (currentNode->right == nullptr) {
            replant(root, currentNode, parent, currentNode->left);
        } else {

            struct node *succ{currentNode->right}, *succParent{nullptr};
            while (succ->left != nullptr) {
                succParent = succ;
                succ = succ->left;
            }

            if (succ == currentNode->right) {
                currentNode->key = succ->key;
                currentNode->right = succ->right;
                delete succ;
            } else {

                int k = succ->key;
                replant(root, succ, succParent, succ->right);
                currentNode->key = k;

            }

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