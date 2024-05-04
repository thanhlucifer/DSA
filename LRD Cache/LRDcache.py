from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        else:
            self.cache.move_to_end(key)  # Move to end to show it was recently used
            return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        elif len(self.cache) >= self.capacity:
            self.cache.popitem(last=False)  # Pop the first item (least recently used)
        self.cache[key] = value

# Example usage
def test_LRUCache(operations, values):
    result = []
    cache = None
    for op, value in zip(operations, values):
        if op == "LRUCache":
            cache = LRUCache(value[0])
            result.append(None)
        elif op == "put":
            cache.put(value[0], value[1])
            result.append(None)
        elif op == "get":
            result.append(cache.get(value[0]))
    return result

operations = ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
values = [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
print(test_LRUCache(operations, values))  # Output: [null, null, null, 1, null, -1, null, -1, 3, 4]
