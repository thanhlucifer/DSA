package Task3.smallestNumber;

public class smallestNumber {

    static final int MAX = 50;

    static void findSmallest(int n) {
        int[] res = new int[MAX];
        int j = 0;

        // Trường hợp 1: Nếu số nhỏ hơn 10
        if (n < 10) {
            System.out.println(n + 10);
            return;
        }

        // Trường hợp 2: Bắt đầu từ 9 và thử từng chữ số
        for (int i = 9; i > 1; i--) {
            // Nếu chia hết cho i, lưu tất cả các chữ số vào res
            while (n % i == 0) {
                n /= i;
                res[j] = i;
                j++;
            }
        }

        // Nếu n không thể phân tích thành chữ số (các ước số nguyên tố của n lớn hơn 9)
        if (n > 10) {
            System.out.println("Not possible");
            return;
        }

        // Nếu kết quả có ít hơn hai chữ số, thêm một chữ số từ trước đó để có kết quả có ít nhất hai chữ số
        if (j < 2) {
            System.out.println(res[j] * 10 + res[j-1]);
            return;
        }

        // In các chữ số của kết quả theo thứ tự ngược lại
        for (int i = j - 1; i >= 0; i--) {
            System.out.print(res[i]);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        findSmallest(1);
        findSmallest(36);
        findSmallest(13);
        findSmallest(100);
    }
}
