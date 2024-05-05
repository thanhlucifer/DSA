class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findDuplicateSubtrees(self, root):
        # Tạo một từ điển để lưu trữ các cây con đã thấy trước đó
        subtree_map = {}
        result = []

        # Hàm đệ quy để duyệt cây và tạo mã định danh cho từng cây con
        def traverse(node):
            if not node:
                return "#"

            # Tạo mã định danh của cây con bên trái
            left_subtree = traverse(node.left)

            # Tạo mã định danh của cây con bên phải
            right_subtree = traverse(node.right)

            # Tạo mã định danh cho cây con hiện tại
            subtree = f"{node.val},{left_subtree},{right_subtree}"

            # Kiểm tra xem cây con đã thấy trước đó chưa
            if subtree in subtree_map:
                # Nếu cây con đã tồn tại trong từ điển, đánh dấu nó là cây con trùng lặp
                if subtree_map[subtree] == 1:
                    result.append(node)
                # Tăng số lần cây con đã thấy được
                subtree_map[subtree] += 1
            else:
                # Nếu cây con chưa thấy, thêm vào từ điển với số lần là 1
                subtree_map[subtree] = 1

            return subtree

        # Bắt đầu duyệt cây từ gốc
        traverse(root)
        
        # Lọc các cây con trùng lặp từ kết quả
        output = []
        for node in result:
            output.append(self.treeToList(node))
            
        return output
    
    def treeToList(self, root):
        if not root:
            return []
        return [root.val] + self.treeToList(root.left) + self.treeToList(root.right)

# Hàm main để kiểm tra
if __name__ == "__main__":
    # Tạo cây nhị phân ví dụ
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.right.left = TreeNode(2)
    root.right.right = TreeNode(4)
    root.right.left.left = TreeNode(4)

    # Tạo một đối tượng của lớp Solution
    solution = Solution()

    # Tìm các cây con trùng lặp
    duplicates = solution.findDuplicateSubtrees(root)

    # In ra các cây con trùng lặp
    print(duplicates)
