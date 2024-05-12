package Task3.grid_illumination;


import java.util.ArrayList;
import java.util.List;

public class GridIllumination {
    
    public static List<Integer> gridIllumination(int n, int[][] lamps, int[][] queries) {
        int[][] grid = new int[n][n];
        List<Integer> ans = new ArrayList<>();

        // Bật đèn và chiếu sáng các ô lân cận
        for (int[] lamp : lamps) {
            int row = lamp[0], col = lamp[1];
            grid[row][col] = 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (row == i || col == j || Math.abs(row - i) == Math.abs(col - j)) {
                        grid[i][j] = 1;
                    }
                }
            }
        }

        // Xử lý các truy vấn và tắt đèn
        for (int[] query : queries) {
            int queryRow = query[0], queryCol = query[1];
            if (grid[queryRow][queryCol] == 1) {
                ans.add(1);
            } else {
                ans.add(0);
            }
            // Tắt đèn và đèn lân cận
            for (int i = queryRow - 1; i <= queryRow + 1; ++i) {
                for (int j = queryCol - 1; j <= queryCol + 1; ++j) {
                    if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 1) {
                        grid[i][j] = 0;
                    }
                }
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        int n = 5;
        int[][] lamps = {{0,0},{4,4}};
        int[][] queries = {{1,1},{1,0}};

        List<Integer> result = gridIllumination(n, lamps, queries);
        for (int x : result) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
}
