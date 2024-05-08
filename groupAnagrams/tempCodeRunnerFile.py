def groupAnagrams(strs):
    anagrams = {}

    for s in strs:
        sorted_s = ''.join(sorted(s))
        if sorted_s in anagrams:
            anagrams[sorted_s].append(s)
        else:
            anagrams[sorted_s] = [s]

    return list(anagrams.values())

# Test
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
result = groupAnagrams(strs)
print(result)
