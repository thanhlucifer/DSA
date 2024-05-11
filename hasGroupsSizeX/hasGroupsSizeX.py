def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def hasGroupsSizeX(deck):
    if not deck:
        return True
    
    freq = {}
    for card in deck:
        freq[card] = freq.get(card, 0) + 1
    
    common_gcd = next(iter(freq.values()))
    for value in freq.values():
        common_gcd = gcd(common_gcd, value)
    
    return common_gcd >= 2

# Test cases
deck1 = [1, 2, 3, 4, 4, 3, 2, 1]
deck2 = [1, 1, 1, 2, 2, 2, 3, 3]
print("Example 1:", hasGroupsSizeX(deck1))
print("Example 2:", hasGroupsSizeX(deck2))
