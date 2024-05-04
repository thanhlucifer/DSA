#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    
    while (curr != NULL || !s.empty()) {
        // Thêm tất cả các nút bên trái của curr vào stack
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        
        // Lấy nút trên cùng của stack là nút gốc
        curr = s.top();
        s.pop();
        
        // Thêm giá trị của nút gốc vào danh sách kết quả
        result.push_back(curr->val);
        
        // Di chuyển đến cây con bên phải của nút gốc
        curr = curr->right;
    }
    
    return result;
}

int main() {
    // Tạo cây nhị phân như ví dụ
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    // In ra kết quả của việc duyệt theo thứ tự trung tố
    vector<int> result = inorderTraversal(root);
    cout << "Inorder traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
