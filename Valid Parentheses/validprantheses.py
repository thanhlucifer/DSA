def is_valid(s: str) -> bool:
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}

    for char in s:
        if char in mapping:
            top_element = stack.pop() if stack else '#'
            if mapping[char] != top_element:
                return False
        else:
            stack.append(char)

    return not stack

# Example usage:
input1 = "()"
input2 = "()[]{}"
input3 = "(]"

print(f"Input 1: {is_valid(input1)}")
print(f"Input 2: {is_valid(input2)}")
print(f"Input 3: {is_valid(input3)}")
