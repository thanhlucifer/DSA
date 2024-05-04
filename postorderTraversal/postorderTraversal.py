class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def postorderTraversal(root):
    result = []
    if root is None:
        return result
    
    stack = []
    current = root
    last_visited = None
    
    while current is not None or stack:
        if current is not None:
            stack.append(current)
            current = current.left
        else:
            top_node = stack[-1]
            if top_node.right is not None and last_visited != top_node.right:
                current = top_node.right
            else:
                result.append(top_node.val)
                last_visited = top_node
                stack.pop()
    
    return result

# Hàm main để kiểm tra
if __name__ == "__main__":
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)

    result = postorderTraversal(root)
    
    print("Postorder Traversal:", result)
