package Task3.segregate0sAnd1s;

import java.util.Arrays;

public class segregate0sAnd1s {
    public static void segregate0sAnd1s(int[] arr) {
        int left = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                int temp = arr[i];
                arr[i] = arr[left];
                arr[left] = temp;
                left++;
            }
        }
    }

    public static void main(String[] args) {
        int[][] arrays = {
            {1, 0, 1, 0, 1, 0, 1, 0, 1},
            {0, 0, 0, 1, 1, 1},
            {1, 1, 1, 1, 0, 0, 0, 0},
            {1, 0},
            {0, 1}
        };

        for (int[] arr : arrays) {
            segregate0sAnd1s(arr);
            System.out.println(Arrays.toString(arr));
        }
    }
}
