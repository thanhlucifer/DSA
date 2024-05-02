#include <iostream>
#include <stack>
#include <string>

std::string decodeString(const std::string& s) {
    std::stack<int> numStack;
    std::stack<std::string> strStack;
    std::string currentStr = "";
    int currentNum = 0;

    for (char c : s) {
        if (std::isdigit(c)) {
            currentNum = currentNum * 10 + (c - '0');
        } else if (c == '[') {
            numStack.push(currentNum);
            strStack.push(currentStr);
            currentNum = 0;
            currentStr = "";
        } else if (c == ']') {
            int repeatTimes = numStack.top();
            numStack.pop();
            std::string prevStr = strStack.top();
            strStack.pop();
            for (int i = 0; i < repeatTimes; ++i) {
                prevStr += currentStr;
            }
            currentStr = prevStr;
        } else {
            currentStr += c;
        }
    }

    return currentStr;
}

int main() {
    std::string s1 = "3[a]2[bc]";
    std::string s2 = "3[a2[c]]";
    std::string s3 = "2[abc]3[cd]ef";

    std::cout << decodeString(s1) << std::endl;  // Output: "aaabcbc"
    std::cout << decodeString(s2) << std::endl;  // Output: "accaccacc"
    std::cout << decodeString(s3) << std::endl;  // Output: "abcabccdcdcdef"

    return 0;
}
