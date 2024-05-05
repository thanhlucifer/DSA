class TreeNode:
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

def build_tree_helper(inorder, levelorder, start, end, index_map):
    if start > end:
        return None

    root = TreeNode(levelorder[0])
    root_index = index_map[root.val]

    left_levelorder = [node for node in levelorder[1:] if index_map[node] < root_index]
    right_levelorder = [node for node in levelorder[1:] if index_map[node] > root_index]

    root.left = build_tree_helper(inorder, left_levelorder, start, root_index - 1, index_map)
    root.right = build_tree_helper(inorder, right_levelorder, root_index + 1, end, index_map)

    return root

def build_tree(inorder, levelorder):
    index_map = {val: i for i, val in enumerate(inorder)}
    return build_tree_helper(inorder, levelorder, 0, len(inorder) - 1, index_map)

def print_inorder(root):
    if root:
        print_inorder(root.left)
        print(root.val, end=" ")
        print_inorder(root.right)

if __name__ == "__main__":
    inorder = [4, 8, 10, 12, 14, 20, 22]
    levelorder = [20, 8, 22, 4, 12, 10, 14]

    root = build_tree(inorder, levelorder)

    print("Inorder traversal of the constructed tree:")
    print_inorder(root)
