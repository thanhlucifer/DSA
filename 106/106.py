class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        index_map = {value: idx for idx, value in enumerate(inorder)}

        def build(in_left, in_right, post_left, post_right):
            if post_left > post_right:
                return None

            root_val = postorder[post_right]
            root = TreeNode(root_val)

            root_index = index_map[root_val]

            # Elements left of the root_index are part of the left subtree
            left_subtree_length = root_index - in_left
            root.left = build(in_left, root_index - 1, post_left, post_left + left_subtree_length - 1)
            root.right = build(root_index + 1, in_right, post_left + left_subtree_length, post_right - 1)

            return root

        return build(0, len(inorder) - 1, 0, len(postorder) - 1)

# Helper function to print tree in preorder traversal
def print_preorder(node):
    if node is None:
        return
    print(node.val, end=' ')
    print_preorder(node.left)
    print_preorder(node.right)

if __name__ == "__main__":
    inorder = [9, 3, 15, 20, 7]
    postorder = [9, 15, 7, 20, 3]
    solution = Solution()
    result_tree = solution.buildTree(inorder, postorder)

    print("Preorder of constructed tree:", end=' ')
    print_preorder(result_tree)
    print()
