#include <iostream>
#include <vector>
using namespace std;

void segregate0sAnd1s(vector<int>& arr) {
    int left = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            swap(arr[i], arr[left]);
            ++left;
        }
    }
}

int main() {
    vector<int> arr1 = {1, 0, 1, 0, 1, 0, 1, 0, 1};
    segregate0sAnd1s(arr1);
    for (int x : arr1) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> arr2 = {0, 0, 0, 1, 1, 1};
    segregate0sAnd1s(arr2);
    for (int x : arr2) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> arr3 = {1, 1, 1, 1, 0, 0, 0, 0};
    segregate0sAnd1s(arr3);
    for (int x : arr3) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> arr4 = {1, 0};
    segregate0sAnd1s(arr4);
    for (int x : arr4) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> arr5 = {0, 1};
    segregate0sAnd1s(arr5);
    for (int x : arr5) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
