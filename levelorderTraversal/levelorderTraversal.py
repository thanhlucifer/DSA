from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def levelOrder(root):
    result = []

    if not root:
        return result

    queue = deque()
    queue.append(root)

    while queue:
        level_values = []
        level_size = len(queue)

        for i in range(level_size):
            node = queue.popleft()
            level_values.append(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(level_values)

    return result

# Tạo cây nhị phân như ví dụ
root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)

res = levelOrder(root)

# In kết quả
for level in res:
    print(level)
