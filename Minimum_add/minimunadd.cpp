#include <bits/stdc++.h>
using namespace std;

int minParentheses(string p) {
    stack<int> stk;
    int ans = 0;
    for (int i = 0; i < p.length(); ++i) {
        if (p[i] == '(') {
            stk.push(i);
        } else {
            if (!stk.empty()) {
                stk.pop();
            } else {
                ans += 1;
            }
        }
    }
    ans += stk.size();
    return ans;
}

int main() {
    string s = "())";
    cout << minParentheses(s);  // Output: 1
    return 0;
}
