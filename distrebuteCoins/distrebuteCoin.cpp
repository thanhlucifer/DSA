#include <iostream>
#include <cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }

private:
    int dfs(TreeNode* node, int& moves) {
        if (!node) return 0;

        int left_excess = dfs(node->left, moves);
        int right_excess = dfs(node->right, moves);

        moves += abs(left_excess) + abs(right_excess);

        return node->val + left_excess + right_excess - 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);

    Solution sol;
    cout << "Minimum moves: " << sol.distributeCoins(root) << endl;

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
