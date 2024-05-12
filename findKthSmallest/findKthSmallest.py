def find_kth_smallest(arr, k):
    removed_numbers = set(arr)
    count = 0
    number = 1

    while True:
        if number not in removed_numbers:
            count += 1
            if count == k:
                return number
        number += 1

    return -1  # Theoretically should never reach this point

# Example usage
arr = [2, 4]
k = 3
print("The {}-th smallest number is: {}".format(k, find_kth_smallest(arr, k)))
