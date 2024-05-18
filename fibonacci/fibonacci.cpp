#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int previous = 0, current = 1;
    for (int i = 2; i <= n; ++i) {
        int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
