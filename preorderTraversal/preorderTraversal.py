from typing import List

# Định nghĩa cấu trúc của một nút trong cây nhị phân
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # Hàm duyệt cây theo thứ tự trước
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        result = []
        self.preorder(root, result)
        return result
    
    # Hàm đệ quy để duyệt cây theo thứ tự trước
    def preorder(self, node: TreeNode, result: List[int]):
        if not node:
            return
        result.append(node.val) # Thêm giá trị của nút vào danh sách kết quả
        self.preorder(node.left, result) # Duyệt qua cây con bên trái
        self.preorder(node.right, result) # Duyệt qua cây con bên phải

# Tạo cây nhị phân tương ứng với ví dụ 1
root = TreeNode(1)
root.right = TreeNode(2)
root.right.left = TreeNode(3)

sol = Solution()
result = sol.preorderTraversal(root)
print("Preorder traversal:", result)
