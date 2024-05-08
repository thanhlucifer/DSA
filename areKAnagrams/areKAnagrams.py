from collections import Counter

def areKAnagrams(str1, str2, k):
    if len(str1) != len(str2):
        return False

    frequencyMap = Counter(str1)

    # Step 2: Adjust frequency map based on str2
    for c in str2:
        if frequencyMap[c] > 0:
            frequencyMap[c] -= 1

    count = sum(frequencyMap.values())

    # Step 3: Count remaining characters in the map
    return count <= k

str1 = "anagram"
str2 = "grammar"
k = 3

if areKAnagrams(str1, str2, k):
    print("Yes")
else:
    print("No")
