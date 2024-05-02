#include <iostream>
#include <stack>
using namespace std;

bool findDuplicateParentheses(string expression) {
    stack<char> st;
    for (char c : expression) {
        if (c == ')') {
            int insideCount = 0;
            while (!st.empty() && st.top() != '(') {
                st.pop();
                insideCount++;
            }
            if (insideCount < 1) {
                return true;
            }
            st.pop(); // Remove the matching '('
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

int main() {
    string expression = "(((a+(b))+(c+d)))";
    if (findDuplicateParentheses(expression)) {
        cout << "Duplicate Found" << endl;
    } else {
        cout << "No Duplicates Found" << endl;
    }
    return 0;
}
