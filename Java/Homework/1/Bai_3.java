import java.io.BufferedReader;
import java.io.IOError;
import java.io.IOException;
import java.io.InputStreamReader;

// Lớp chính
public class Bai_3 {
    // Hàm chính
    public static void main(String[] args) throws IOError, IOException {
        // Khởi tạo 1 object của lớp BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Prompt user nhập dãy số
        System.out.print("Nhập dãy số nguyên: ");

        // Nhập dãy số trong 1 dòng, ngăn cách bởi 1 dấu cách hoặc 1 dấu phẩy
        String[] arr = br.readLine().trim().split("[,\\s+]");

        // Khởi tạo 1 mảng số nguyên
        int[] a = new int[arr.length];

        // Chuyển đổi string thành các phần từ của mảng
        for (int i = 0; i < a.length; i++)
            a[i] = Integer.parseInt(arr[i]);

        // Hiển thị mảng ra màn hình
        System.out.print("Dãy số vừa nhập: ");
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
    }
}
