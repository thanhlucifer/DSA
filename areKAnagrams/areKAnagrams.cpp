#include <iostream>
#include <unordered_map>
using namespace std;

bool areKAnagrams(string str1, string str2, int k) {
    if (str1.length() != str2.length())
        return false;

    unordered_map<char, int> frequencyMap;

    // Step 1: Create frequency map for str1
    for (char c : str1)
        frequencyMap[c]++;

    // Step 2: Adjust frequency map based on str2
    for (char c : str2) {
        if (frequencyMap[c] > 0)
            frequencyMap[c]--;
    }

    int count = 0;

    // Step 3: Count remaining characters in the map
    for (auto it : frequencyMap)
        count += it.second;

    return count <= k;
}

int main() {
    string str1 = "hello";
    string str2 = "world";
    int k = 2;

    if (areKAnagrams(str1, str2, k))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
