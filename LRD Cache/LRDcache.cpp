#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> cacheList;  // doubly linked list to store key-value pairs
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;  // map from keys to list iterators

    void moveToFront(int key, int value) {
        // Remove the old entry from the list
        cacheList.erase(cache[key]);
        // Insert the updated entry at the front
        cacheList.push_front(std::make_pair(key, value));
        // Update the map to point to the new location
        cache[key] = cacheList.begin();
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;  // key not found
        auto value = cache[key]->second;
        moveToFront(key, value);
        return value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key already exists, update the value and move to front
            moveToFront(key, value);
        } else {
            // Check if we have reached the capacity
            if (cacheList.size() == capacity) {
                // Remove the least recently used item from cache and list
                auto lru = cacheList.back();
                cache.erase(lru.first);
                cacheList.pop_back();
            }
            // Insert the new item at the front
            cacheList.push_front(std::make_pair(key, value));
            cache[key] = cacheList.begin();
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl;  // prints 1
    cache.put(3, 3);                         // evicts key 2
    std::cout << cache.get(2) << std::endl;  // prints -1 (not found)
    cache.put(4, 4);                         // evicts key 1
    std::cout << cache.get(1) << std::endl;  // prints -1 (not found)
    std::cout << cache.get(3) << std::endl;  // prints 3
    std::cout << cache.get(4) << std::endl;  // prints 4
    return 0;
}
