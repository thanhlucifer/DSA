class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        def serialize_helper(node):
            if not node:
                return 'null,'
            serialized_tree = str(node.val) + ','
            serialized_tree += serialize_helper(node.left)
            serialized_tree += serialize_helper(node.right)
            return serialized_tree
        
        return serialize_helper(root)

    def deserialize(self, data: str) -> TreeNode:
        def deserialize_helper(nodes):
            val = next(nodes)
            if val == 'null':
                return None
            node = TreeNode(int(val))
            node.left = deserialize_helper(nodes)
            node.right = deserialize_helper(nodes)
            return node
        
        nodes = iter(data.split(','))
        return deserialize_helper(nodes)

# Function to print the tree
def printTree(root):
    if root:
        print(root.val, end=" ")
        printTree(root.left)
        printTree(root.right)

# Test
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.right.left = TreeNode(4)
root.right.right = TreeNode(5)

codec = Codec()
serialized_tree = codec.serialize(root)
print("Serialized tree:", serialized_tree)

deserialized_root = codec.deserialize(serialized_tree)
print("Deserialized tree:")
printTree(deserialized_root) # In cây nhị phân đã deserialize


