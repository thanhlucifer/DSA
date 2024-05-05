#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& levelorder, int start, int end, unordered_map<int, int>& map) {
    if (start > end)
        return nullptr;

    TreeNode* root = new TreeNode(levelorder[0]);
    int rootIndex = map[root->val];

    vector<int> leftLevelOrder, rightLevelOrder;
    for (int i = 1; i < levelorder.size(); ++i) {
        int index = map[levelorder[i]];
        if (index < rootIndex)
            leftLevelOrder.push_back(levelorder[i]);
        else if (index > rootIndex)
            rightLevelOrder.push_back(levelorder[i]);
    }

    root->left = buildTreeHelper(inorder, leftLevelOrder, start, rootIndex - 1, map);
    root->right = buildTreeHelper(inorder, rightLevelOrder, rootIndex + 1, end, map);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& levelorder) {
    unordered_map<int, int> map;
    for (int i = 0; i < inorder.size(); ++i)
        map[inorder[i]] = i;

    return buildTreeHelper(inorder, levelorder, 0, inorder.size() - 1, map);
}

void printInorder(TreeNode* root) {
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder = {4, 8, 10, 12, 14, 20, 22};
    vector<int> levelorder = {20, 8, 22, 4, 12, 10, 14};

    TreeNode* root = buildTree(inorder, levelorder);

    cout << "Inorder traversal of the constructed tree:\n";
    printInorder(root);
    cout << endl;

    return 0;
}
