#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;
    Node(int data) {
        key = data;
        left = right = nullptr;
    }
};

bool printAncestors(Node *root, int key) {
    if (root == nullptr)
        return false;

    if (root->key == key)
        return true;

    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        cout << root->key << " ";
        return true;
    }

    return false;
}

int main() {
    // Example binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);

    int key = 8;
    cout << "Ancestors of " << key << ": ";
    printAncestors(root, key);
    cout << endl;

    return 0;
}
