def find_smallest(n):
    MAX = 50
    res = [0] * MAX
    j = 0

    # Trường hợp 1: Nếu số nhỏ hơn 10
    if n < 10:
        print(n + 10)
        return

    # Trường hợp 2: Bắt đầu từ 9 và thử từng chữ số
    for i in range(9, 1, -1):
        # Nếu chia hết cho i, lưu tất cả các chữ số vào res
        while n % i == 0:
            n //= i
            res[j] = i
            j += 1

    # Nếu n không thể phân tích thành chữ số (các ước số nguyên tố của n lớn hơn 9)
    if n > 10:
        print("Not possible")
        return

    # Nếu kết quả có ít hơn hai chữ số, thêm một chữ số từ trước đó để có kết quả có ít nhất hai chữ số
    if j < 2:
        print(res[j] * 10 + res[j-1])
        return

    # In các chữ số của kết quả theo thứ tự ngược lại
    for i in range(j - 1, -1, -1):
        print(res[i], end="")
    print()

# Kiểm tra hàm
find_smallest(1)
find_smallest(36)
find_smallest(13)
find_smallest(100)
