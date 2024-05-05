#include <iostream>
#include <unordered_map>
#include <string>
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> subtreeCount;
        traverse(root, subtreeCount, result);
        return result;
    }
    
    // Hàm đệ quy để duyệt cây
    string traverse(TreeNode* node, unordered_map<string, int>& subtreeCount, vector<TreeNode*>& result) {
        if (!node) return "#"; // Node null được biểu diễn bằng "#"
        
        // Tạo mã định danh cho cây con bên trái và bên phải
        string leftSubtree = traverse(node->left, subtreeCount, result);
        string rightSubtree = traverse(node->right, subtreeCount, result);
        
        // Tạo mã định danh cho cây con hiện tại
        string subtree = to_string(node->val) + "," + leftSubtree + "," + rightSubtree;
        
        // Kiểm tra xem cây con đã thấy trước đó chưa
        if (subtreeCount[subtree] == 1) {
            // Nếu cây con đã tồn tại trong từ điển, đánh dấu nó là cây con trùng lặp
            result.push_back(node);
        }
        
        // Tăng số lần cây con đã thấy được
        subtreeCount[subtree]++;
        
        return subtree;
    }
};

int main() {
    // Khởi tạo cây nhị phân như ví dụ
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);

    Solution sol;
    vector<TreeNode*> duplicates = sol.findDuplicateSubtrees(root);

    // In ra các cây con trùng lặp
    for (TreeNode* node : duplicates) {
        cout << node->val << " ";
    }

    return 0;
}
