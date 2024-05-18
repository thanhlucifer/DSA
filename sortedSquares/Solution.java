package Task3.sortedSquares;


import java.util.Arrays;

public class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int left = 0, right = n - 1, pos = n - 1;
        
        while (left <= right) {
            if (Math.abs(nums[left]) >= Math.abs(nums[right])) {
                result[pos] = nums[left] * nums[left];
                left++;
            } else {
                result[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;
        }
        
        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {-4, -1, 0, 3, 10};
        int[] result = sol.sortedSquares(nums);
        System.out.println(Arrays.toString(result));
    }
}
