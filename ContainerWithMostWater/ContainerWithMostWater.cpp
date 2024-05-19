#include <iostream>
#include <vector>
#include <algorithm> // std::min, std::max

using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;
    
    while (left < right) {
        int currentHeight = min(height[left], height[right]);
        int currentWidth = right - left;
        int currentArea = currentHeight * currentWidth;
        maxArea = max(maxArea, currentArea);
        
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }
    
    return maxArea;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Area: " << maxArea(height) << endl;
    return 0;
}
