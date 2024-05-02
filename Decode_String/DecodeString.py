def decode_string(s: str) -> str:
    stack = []
    current_num = 0
    current_str = ""

    for char in s:
        if char.isdigit():
            current_num = current_num * 10 + int(char)
        elif char == "[":
            stack.append((current_num, current_str))
            current_num = 0
            current_str = ""
        elif char == "]":
            num, prev_str = stack.pop()
            current_str = prev_str + num * current_str
        else:
            current_str += char

    return current_str

# Ví dụ sử dụng:
s1 = "3[a]2[bc]"
s2 = "3[a2[c]]"
s3 = "2[abc]3[cd]ef"

print(decode_string(s1))  # Output: "aaabcbc"
print(decode_string(s2))  # Output: "accaccacc"
print(decode_string(s3))  # Output: "abcabccdcdcdef"
