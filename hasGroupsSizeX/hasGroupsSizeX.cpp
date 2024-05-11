#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool hasGroupsSizeX(vector<int>& deck) {
    if (deck.empty())
        return true;
    
    unordered_map<int, int> freq;
    for (int card : deck) {
        freq[card]++;
    }
    
    int common_gcd = freq.begin()->second;
    for (auto& pair : freq) {
        common_gcd = gcd(common_gcd, pair.second);
    }
    
    return common_gcd >= 2;
}

int main() {
    vector<int> deck1 = {1, 2, 3, 4, 4, 3, 2, 1};
    vector<int> deck2 = {1, 1, 1, 2, 2, 2, 3, 3};
    
    cout << "Example 1: " << (hasGroupsSizeX(deck1) ? "true" : "false") << endl;
    cout << "Example 2: " << (hasGroupsSizeX(deck2) ? "true" : "false") << endl;
    
    return 0;
}
