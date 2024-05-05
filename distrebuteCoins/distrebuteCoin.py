class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def distributeCoins(self, root: TreeNode) -> int:
        moves = [0]
        self.dfs(root, moves)
        return moves[0]

    def dfs(self, node: TreeNode, moves: list) -> int:
        if not node:
            return 0

        left_excess = self.dfs(node.left, moves)
        right_excess = self.dfs(node.right, moves)

        moves[0] += abs(left_excess) + abs(right_excess)

        return node.val + left_excess + right_excess - 1

# Tạo cây nhị phân từ ví dụ 1
root = TreeNode(3)
root.left = TreeNode(0)
root.right = TreeNode(0)

sol = Solution()
print("Minimum moves:", sol.distributeCoins(root))
