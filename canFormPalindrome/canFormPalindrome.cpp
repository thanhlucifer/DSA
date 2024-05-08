#include <iostream>
#include <string>
using namespace std;

bool canFormPalindrome(const string& s) {
    int count[256] = {0}; // Tạo mảng đếm với kích thước bảng mã ASCII

    // Đếm tần suất của mỗi ký tự
    for (char c : s) {
        count[c]++;
    }

    int oddCount = 0;

    // Kiểm tra số lượng ký tự có tần suất lẻ
    for (int i = 0; i < 256; i++) {
        if (count[i] % 2 != 0) {
            oddCount++;
        }

        // Nếu có nhiều hơn một ký tự có tần suất lẻ, chuỗi không thể là đối xứng
        if (oddCount > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    if (canFormPalindrome(s)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
