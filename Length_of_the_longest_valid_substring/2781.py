def find_max_len(s):
    n = len(s)  # Get the length of the input string
    stk = []  # Create an empty stack to store indices of '('
    result = 0  # Variable to store the maximum length of valid substring
    last = n    # Variable to keep track of the last index

    # Traverse the input string
    for i in range(n):
        if s[i] == '(':  # If current character is '('
            stk.append(i)  # Push its index onto the stack
        else:
            # If stack is not empty and top of stack contains '('
            if stk and s[stk[-1]] == '(':
                stk.pop()  # Pop the index of '(' from the stack
            else:
                # Push current index onto stack as base for next valid substring
                stk.append(i)

    # After traversing the string, calculate the length of longest valid substring
    while stk:
        now = stk.pop()  # Pop the index of '(' from stack
        # Calculate the length of valid substring
        result = max(result, last - now - 1)
        last = now  # Update last index

    # Return the maximum length of valid substring
    return max(result, last)


# Driver code
if __name__ == "__main__":
    s = "((()()"  # Test string 1
    # Output: 4 (Length of the longest valid substring is 4)
    print(find_max_len(s))

    s = "()(()))))"  # Test string 2
    # Output: 6 (Length of the longest valid substring is 6)
    print(find_max_len(s))