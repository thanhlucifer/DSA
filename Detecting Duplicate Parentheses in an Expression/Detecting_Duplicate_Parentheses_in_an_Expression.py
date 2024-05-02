def find_duplicate_parentheses(expression):
    stack = []
    for char in expression:
        if char == ')':
            inside_count = 0
            while stack and stack[-1] != '(':
                stack.pop()
                inside_count += 1
            if inside_count < 1:
                return True
            stack.pop()  # Remove the matching '('
        else:
            stack.append(char)
    return not stack

# Example usage
expression = "(((a+(b))+(c+d)))"
if find_duplicate_parentheses(expression):
    print("Duplicate Found")
else:
    print("No Duplicates Found")
