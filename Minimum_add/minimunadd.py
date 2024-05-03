def minParentheses(s):
    stk = []
    ans = 0
    for i, char in enumerate(s):
        if char == '(':
            stk.append(i)
        else:
            if stk:
                stk.pop()
            else:
                ans += 1
    ans += len(stk)
    return ans

# Ví dụ sử dụng
s = "((("
print(minParentheses(s))  # Output: 1
