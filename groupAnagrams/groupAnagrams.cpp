#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;

    for (const string& s : strs) {
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        if (anagrams.find(sorted_s) != anagrams.end()) {
            anagrams[sorted_s].push_back(s);
        } else {
            anagrams[sorted_s] = {s};
        }
    }

    vector<vector<string>> result;
    for (auto& pair : anagrams) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    
    for (const auto& group : result) {
        for (const string& s : group) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
