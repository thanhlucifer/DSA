class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def print_ancestors(root, key):
    if root is None:
        return False
    
    if root.key == key:
        return True
    
    if (print_ancestors(root.left, key) or print_ancestors(root.right, key)):
        print(root.key, end=" ")
        return True
    
    return False

# Example binary tree
def create_example_tree():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.left.left.left = Node(8)
    return root

root = create_example_tree()
key = 8
print("Ancestors of", key, ":", end=" ")
print_ancestors(root, key)
print()
