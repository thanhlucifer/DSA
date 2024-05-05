#include <iostream>
#include <vector>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Hàm xây dựng cây BST từ dãy duyệt hậu tố
Node* buildBSTFromPostorder(vector<int>& postorder, int& index, int minVal, int maxVal) {
    if (index < 0)
        return nullptr;
    
    int val = postorder[index];
    if (val < minVal || val > maxVal)
        return nullptr;

    Node* root = new Node(val);
    index--;

    // Xây dựng cây con bên phải trước
    root->right = buildBSTFromPostorder(postorder, index, val, maxVal);
    
    // Xây dựng cây con bên trái
    root->left = buildBSTFromPostorder(postorder, index, minVal, val);

    return root;
}

// Hàm duyệt cây theo thứ tự trung tố và in ra màn hình
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Hàm chính
void mainFunction(vector<int>& postorder) {
    int index = postorder.size() - 1;
    Node* root = buildBSTFromPostorder(postorder, index, INT_MIN, INT_MAX);
    
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
}

int main() {
    vector<int> postorder = {1, 7, 5, 50, 40, 10};
    mainFunction(postorder);
    return 0;
}
