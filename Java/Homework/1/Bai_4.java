import java.io.BufferedReader;
import java.io.IOError;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// Lớp chính
public class Bai_4 {
    // Hàm sắp xếp
    void Sort(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            int min = i;

            for (int j = i + 1; j < a.length; j++) {
                if (a[j] < a[min])
                    min = j;
            }

            int tmp = a[min];
            a[min] = a[i];
            a[i] = tmp;
        }
    }

    // Hàm kiểm tra nguyên tố
    boolean isPrime(int num) {
        int j = 2;
        boolean iP = false;
        while (j <= Math.sqrt(num)) {
            if (num % j == 0) {
                iP = true;
                break;
            }
            j++;
        }
        return iP;
    }

    // Hàm xuất kết quả
    void Output(String prompt, int[] a) {
        System.out.print(prompt);
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    // Hàm chính
    public static void main(String[] args) throws IOError, IOException {
        // Khởi tạo các object
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Bai_4 b4 = new Bai_4();

        // Prompt user nhập dãy số
        System.out.print("Nhập dãy số nguyên: ");

        /*
         * Nhập dãy số trong 1 dòng, ngăn cách bởi 1 dấu cách hoặc 1 dấu phẩy
         * Sau bước này ta được chuỗi có độ dài là số lượng phần tử
         */
        String[] arr = br.readLine().trim().split("[,\\s+]");

        /*
         * Khởi tạo mảng số nguyên với kích thước có độ dài như trên
         * Chuyển đổi string thành các phần từ của mảng
         */
        int[] a = new int[arr.length];
        for (int i = 0; i < a.length; i++)
            a[i] = Integer.parseInt(arr[i]);

        // Hiển thị dãy số vừa nhập
        b4.Output("Dãy số vừa nhập: ", a);

        // Khởi tạo biến tính tống s = 0
        int s = 0;
        for (int i = 0; i < a.length; i++)
            s += a[i];
        System.out.println("Tổng dãy số là: " + s);

        /*
         * Sắp xếp dãy số tăng dần, sử dụng thuật toán sắp xếp chọn
         * và hiển thị dãy sô
         */
        b4.Sort(a);
        b4.Output("Dãy số đã sắp xếp: ", a);

        /*
         * Chia thành 2 dãy con, dãy số nguyên tố và dãy số nguyên tố
         * và hiển thị 2 dãy số
         */
        int[] b = new int[0], c = new int[0];
        for (int i = 0; i < a.length; i++) {
            if (!b4.isPrime(a[i])) {
                b = Arrays.copyOf(b, b.length + 1);
                b[b.length - 1] = a[i];
            } else {
                c = Arrays.copyOf(c, c.length + 1);
                c[c.length - 1] = a[i];
            }
        }
        b4.Output("Dãy số nguyên tố: ", b);
        b4.Output("Dãy hợp số: ", c);
    }
}
