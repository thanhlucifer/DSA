package Task3.merge_k_sorted_arrays;


import java.util.*;

class Solution {
    static class Tuple {
        int val, row, col;
        Tuple(int val, int row, int col) {
            this.val = val;
            this.row = row;
            this.col = col;
        }
    }

    static class Compare implements Comparator<Tuple> {
        public int compare(Tuple a, Tuple b) {
            return a.val - b.val;
        }
    }

    public static List<Integer> mergeKSortedArrays(int[][] matrix) {
        List<Integer> merged = new ArrayList<>();
        PriorityQueue<Tuple> pq = new PriorityQueue<>(new Compare());
        
        // Push the first element from each array into the priority queue
        for (int i = 0; i < matrix.length; ++i) {
            pq.offer(new Tuple(matrix[i][0], i, 0));
        }
        
        while (!pq.isEmpty()) {
            Tuple tuple = pq.poll();
            merged.add(tuple.val);
            int row = tuple.row;
            int col = tuple.col;
            
            // Push the next element from the same row into the priority queue
            if (col + 1 < matrix[row].length) {
                pq.offer(new Tuple(matrix[row][col + 1], row, col + 1));
            }
        }
        
        return merged;
    }

    public static void main(String[] args) {
        int[][] matrix = {{1, 3, 5}, {2, 4, 6}, {7, 8, 9}};
        List<Integer> result = mergeKSortedArrays(matrix);
        System.out.print("Merged array: ");
        for (int num : result) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
