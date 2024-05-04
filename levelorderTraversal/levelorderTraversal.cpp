#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    
    if (root == NULL) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        vector<int> level_values;
        int level_size = q.size();

        for (int i = 0; i < level_size; i++) {
            TreeNode* node = q.front();
            q.pop();

            level_values.push_back(node->val);

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }

        result.push_back(level_values);
    }

    return result;
}

int main() {
    // Tạo cây nhị phân như ví dụ
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = levelOrder(root);

    // In kết quả
    for (auto& level : res) {
        cout << "[";
        for (auto& val : level) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
