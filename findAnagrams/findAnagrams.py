from collections import Counter
from typing import List

def findAnagrams(s: str, p: str) -> List[int]:
    result = []
    window = Counter()
    p_freq = Counter(p)

    left, right = 0, 0

    while right < len(s):
        window[s[right]] += 1
        right += 1

        if right - left > len(p):
            window[s[left]] -= 1
            if window[s[left]] == 0:
                del window[s[left]]
            left += 1

        if right - left == len(p):
            if window == p_freq:
                result.append(left)

    return result

s = "cbaebabacd"
p = "abc"
print(findAnagrams(s, p))
