#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int count = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[count] = nums[i];
            count++;
        }
    }
    
    return count;
}

int main() {
    std::vector<int> nums = {1, 1, 2};
    int k = removeDuplicates(nums);

    std::cout << "Output: " << k << ", nums = [";
    for (int i = 0; i < k; ++i) {
        std::cout << nums[i];
        if (i < k - 1) {
            std::cout << ", ";
        }
    }
    std::cout << ", _]" << std::endl;

    return 0;
}
