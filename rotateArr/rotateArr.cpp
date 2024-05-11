#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0 || k == 0) return;

    k = k % n;
    if (k < 0) k += n;

    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);
    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}
