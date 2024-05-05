#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    unordered_map<int, int> indexMap;
    vector<int> postorder;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->postorder = postorder;
        for (int i = 0; i < inorder.size(); ++i) {
            indexMap[inorder[i]] = i;
        }
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* build(int inLeft, int inRight, int postLeft, int postRight) {
        if (postLeft > postRight) {
            return nullptr;
        }
        
        int rootVal = postorder[postRight];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = indexMap[rootVal];

        root->left = build(inLeft, rootIndex - 1, postLeft, postLeft + rootIndex - inLeft - 1);
        root->right = build(rootIndex + 1, inRight, postLeft + rootIndex - inLeft, postRight - 1);

        return root;
    }
};

// Helper function to print tree in preorder traversal
void printPreorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution solution;
    TreeNode* resultTree = solution.buildTree(inorder, postorder);

    cout << "Preorder of constructed tree: ";
    printPreorder(resultTree);
    cout << endl;

    return 0;
}
