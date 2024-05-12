def grid_illumination(n, lamps, queries):
    grid = [[0] * n for _ in range(n)]
    ans = []

    # Bật đèn và chiếu sáng các ô lân cận
    for lamp in lamps:
        row, col = lamp
        grid[row][col] = 1
        for i in range(n):
            for j in range(n):
                if row == i or col == j or abs(row - i) == abs(col - j):
                    grid[i][j] = 1

    # Xử lý các truy vấn và tắt đèn
    for query_row, query_col in queries:
        if grid[query_row][query_col] == 1:
            ans.append(1)
        else:
            ans.append(0)
        # Tắt đèn và đèn lân cận
        for i in range(query_row - 1, query_row + 2):
            for j in range(query_col - 1, query_col + 2):
                if 0 <= i < n and 0 <= j < n and grid[i][j] == 1:
                    grid[i][j] = 0

    return ans

# Sử dụng ví dụ 1 để kiểm tra
n = 5
lamps = [[0,0],[4,4]]
queries = [[1,1],[1,0]]
print(grid_illumination(n, lamps, queries))  # Output: [1, 0]
