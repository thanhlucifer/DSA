def removeDuplicates(nums):
    if not nums:
        return 0
    
    count = 1
    for i in range(1, len(nums)):
        if nums[i] != nums[i - 1]:
            nums[count] = nums[i]
            count += 1
    
    return count, nums[:count]

if __name__ == "__main__":
    nums = [1, 1, 2]
    k, modified_nums = removeDuplicates(nums)
    print("Output:", k, ", nums =", modified_nums + [None]*(len(nums)-k))
