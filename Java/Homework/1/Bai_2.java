import java.io.BufferedReader;
import java.io.IOError;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

// Lớp chính
public class Bai_2 {
    // Hàm chính
    public static void main(String[] args) throws IOError, IOException {
        // Khởi tạo object của lớp Scanner
        Scanner sc = new Scanner(System.in);

        // Nhập 2 số a và b
        System.out.print("Nhập số thứ nhất: ");
        int a = sc.nextInt();
        System.out.print("Nhập số thứ hai: ");
        int b = sc.nextInt();

        // Hiển thị kết quả
        System.out.println(a + " + " + b + " = " + (a + b));
        System.out.println(a + " - " + b + " = " + (a - b));
        System.out.println(a + " * " + b + " = " + (a * b));
        System.out.println(a + " / " + b + " = " + (a / b));
        System.out.println(a + " % " + b + " = " + (a % b));

        // Khởi tạo object của lớp Bufferedreaderg
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Nhập 2 số c và d
        System.out.print("Nhập số thứ nhất: ");
        int c = Integer.parseInt(br.readLine());
        System.out.print("Nhập số thứ hai: ");
        int d = Integer.parseInt(br.readLine());

        // Hiển thị kết quả
        System.out.println(c + " + " + d + " = " + (c + d));
        System.out.println(c + " - " + d + " = " + (c - d));
        System.out.println(c + " * " + d + " = " + (c * d));
        System.out.println(c + " / " + d + " = " + (c / d));
        System.out.println(c + " % " + d + " = " + (c % d));

        // Đóng scanner
        sc.close();
    }
}
