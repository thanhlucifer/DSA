#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Serialize a tree to a string
    string serialize(TreeNode* root) {
        if (!root)
            return "null,";

        string serialized_tree = to_string(root->val) + ",";
        serialized_tree += serialize(root->left);
        serialized_tree += serialize(root->right);

        return serialized_tree;
    }

    // Deserialize a string to a tree
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize_helper(ss);
    }

private:
    TreeNode* deserialize_helper(stringstream& ss) {
        string val;
        getline(ss, val, ',');
        if (val == "null")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserialize_helper(ss);
        node->right = deserialize_helper(ss);

        return node;
    }
};

// Function to print the tree
void printTree(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

// Test
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized_tree = codec.serialize(root);
    cout << "Serialized tree: " << serialized_tree << endl;

    TreeNode* deserialized_root = codec.deserialize(serialized_tree);
    cout << "Deserialized tree: " << endl;
    printTree(deserialized_root); // In cây nhị phân đã deserialize
    return 0;
    
    return 0;
}
