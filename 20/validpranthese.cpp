#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string s) {
    std::stack<char> st;
    std::unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char c : s) {
        if (mapping.find(c) != mapping.end()) {
            char top_element = st.empty() ? '#' : st.top();
            if (top_element != mapping[c]) {
                return false;
            }
            st.pop();
        } else {
            st.push(c);
        }
    }

    return st.empty();
}

int main() {
    std::string input1 = "()";
    std::string input2 = "()[]{}";
    std::string input3 = "(]";

    std::cout << "Input 1: " << (isValid(input1) ? "true" : "false") << std::endl;
    std::cout << "Input 2: " << (isValid(input2) ? "true" : "false") << std::endl;
    std::cout << "Input 3: " << (isValid(input3) ? "true" : "false") << std::endl;

    return 0;
}
