package Task3.findKthSmallest;


import java.util.HashSet;
import java.util.Set;

public class Main {
    public static int findKthSmallest(int[] arr, int k) {
        Set<Integer> removedNumbers = new HashSet<>();
        for (int num : arr) {
            removedNumbers.add(num);
        }

        int count = 0;
        int number = 1;

        while (true) {
            if (!removedNumbers.contains(number)) {
                count++;
                if (count == k) {
                    return number;
                }
            }
            number++;
        }
    }

    public static void main(String[] args) {
        int[] arr = {2, 4};
        int k = 3;
        System.out.println("The " + k + "-th smallest number is: " + findKthSmallest(arr, k));
    }
}
