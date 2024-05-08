def can_form_palindrome(s):
    count = [0] * 256  # Tạo mảng đếm với kích thước bảng mã ASCII

    # Đếm tần suất của mỗi ký tự
    for char in s:
        count[ord(char)] += 1

    odd_count = 0

    # Kiểm tra số lượng ký tự có tần suất lẻ
    for c in count:
        if c % 2 != 0:
            odd_count += 1

        # Nếu có nhiều hơn một ký tự có tần suất lẻ, chuỗi không thể là đối xứng
        if odd_count > 1:
            return False
    return True

# Nhập chuỗi từ người dùng và kiểm trageeksforgeeks
s = input("Enter the string: ")
if can_form_palindrome(s):
    print("Yes")
else:
    print("No")
