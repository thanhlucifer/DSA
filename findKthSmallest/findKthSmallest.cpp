#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int findKthSmallest(vector<int>& arr, int k) {
    unordered_set<int> removedNumbers(arr.begin(), arr.end());
    int count = 0;
    int number = 1;

    while (true) {
        if (removedNumbers.find(number) == removedNumbers.end()) {
            count++;
            if (count == k) {
                return number;
            }
        }
        number++;
    }
    
    return -1; // In case k is out of natural number range (should theoretically never hit this)
}

int main() {
    vector<int> arr = {2, 4};
    int k = 3;
    cout << "The " << k << "-th smallest number is: " << findKthSmallest(arr, k) << endl;
    return 0;
}
