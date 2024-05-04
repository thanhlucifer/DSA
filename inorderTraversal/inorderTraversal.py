# Định nghĩa cấu trúc của một nút trong cây nhị phân
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorderTraversal(root):
    result = []
    stack = []
    curr = root
    
    while curr or stack:
        # Thêm tất cả các nút bên trái của curr vào stack
        while curr:
            stack.append(curr)
            curr = curr.left
        
        # Lấy nút trên cùng của stack là nút gốc
        curr = stack.pop()
        
        # Thêm giá trị của nút gốc vào danh sách kết quả
        result.append(curr.val)
        
        # Di chuyển đến cây con bên phải của nút gốc
        curr = curr.right
    
    return result

# Tạo cây nhị phân như ví dụ
root = TreeNode(1)
root.right = TreeNode(2)
root.right.left = TreeNode(3)

# In ra kết quả của việc duyệt theo thứ tự trung tố
print("Inorder traversal:", inorderTraversal(root))
