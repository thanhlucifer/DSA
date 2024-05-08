#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    array<int, 26> window = {0};
    array<int, 26> pFreq = {0};

    for (char c : p) {
        pFreq[c - 'a']++;
    }

    int left = 0, right = 0;

    while (right < s.size()) {
        window[s[right] - 'a']++;
        right++;

        if (right - left > p.size()) {
            window[s[left] - 'a']--;
            left++;
        }

        if (right - left == p.size()) {
            bool isAnagram = true;
            for (int i = 0; i < 26; ++i) {
                if (window[i] != pFreq[i]) {
                    isAnagram = false;
                    break;
                }
            }
            if (isAnagram) {
                result.push_back(left);
            }
        }
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> result = findAnagrams(s, p);

    cout << "Indices of anagrams: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
