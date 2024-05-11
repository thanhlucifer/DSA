package Task3.removeDuplicates;

public class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        
        int count = 1;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[count] = nums[i];
                count++;
            }
        }
        
        return count;
    }
    
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1, 1, 2};
        int k = solution.removeDuplicates(nums);

        System.out.print("Output: " + k + ", nums = [");
        for (int i = 0; i < k; ++i) {
            System.out.print(nums[i]);
            if (i < k - 1) {
                System.out.print(", ");
            }
        }
        System.out.println(", _]");
    }
}
