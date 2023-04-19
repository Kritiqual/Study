import java.io.BufferedReader;
import java.io.IOError;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

// Lớp chính
public class Bai_1 {
    // Hàm chính
    public static void main(String[] args) throws IOError, IOException {
        // Khởi tạo 1 object sc lớp Scanner
        Scanner sc = new Scanner(System.in);
        // Prompt user nhập a
        System.out.print("Nhập String a: ");
        // Nhập string a
        String a = sc.nextLine();
        // Hiển thị kết quả
        System.out.println("String a: " + a);

        // Khởi tạo 1 object của lớp BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Prompt user nhập b
        System.out.print("Nhập String b: ");
        // Nhập string b
        String b = br.readLine();
        // Hiển thị kết quả
        System.out.println("String b: " + b);

        // Đóng scanner
        sc.close();
    }
}
