#include <iostream>
#include <vector>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Hàm duyệt cây theo thứ tự trước
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
    
    // Hàm đệ quy để duyệt cây theo thứ tự trước
    void preorder(TreeNode* node, vector<int>& result) {
        if (node == NULL) return;
        result.push_back(node->val); // Thêm giá trị của nút vào danh sách kết quả
        preorder(node->left, result); // Duyệt qua cây con bên trái
        preorder(node->right, result); // Duyệt qua cây con bên phải
    }
};

int main() {
    // Tạo cây nhị phân tương ứng với ví dụ 1
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    cout << "Preorder traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
