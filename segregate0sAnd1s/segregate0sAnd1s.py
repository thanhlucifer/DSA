def segregate0sAnd1s(arr):
    left = 0
    for i in range(len(arr)):
        if arr[i] == 0:
            arr[i], arr[left] = arr[left], arr[i]
            left += 1
    return arr

# Test examples
arrays = [
    [1, 0, 1, 0, 1, 0, 1, 0, 1],
    [0, 0, 0, 1, 1, 1],
    [1, 1, 1, 1, 0, 0, 0, 0],
    [1, 0],
    [0, 1]
]

for arr in arrays:
    print(segregate0sAnd1s(arr))
