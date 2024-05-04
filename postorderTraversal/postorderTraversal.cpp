#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == NULL) 
        return result;
    
    stack<TreeNode*> s;
    TreeNode* current = root;
    TreeNode* lastVisited = NULL;
    
    while (current != NULL || !s.empty()) {
        if (current != NULL) {
            s.push(current);
            current = current->left;
        }
        else {
            TreeNode* topNode = s.top();
            if (topNode->right != NULL && lastVisited != topNode->right) {
                current = topNode->right;
            } else {
                result.push_back(topNode->val);
                lastVisited = topNode;
                s.pop();
            }
        }
    }
    
    return result;
}

// Hàm main để kiểm tra
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    vector<int> result = postorderTraversal(root);
    
    cout << "Postorder Traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
