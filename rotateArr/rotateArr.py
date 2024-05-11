def rotate(nums, k):
    n = len(nums)
    if n == 0 or k == 0:
        return nums

    k = k % n
    if k < 0:
        k += n

    nums[:] = nums[::-1]
    nums[:k] = nums[:k][::-1]
    nums[k:] = nums[k:][::-1]
    return nums

# Example usage
nums = [1, 2, 3, 4, 5, 6, 7]
k = 3
rotate(nums, k)
print(nums)
