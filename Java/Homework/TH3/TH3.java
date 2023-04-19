import java.util.Scanner; // Import thư viện cần thiết

public class TH3 { // Khai báo lớp chính
    public static void main(String[] args) { // Khai báo phương thức chính
        Hanghoa[] DSH; // Khai báo mảng Danh Sách Hàng (DSH)
        Scanner scn = new Scanner(System.in); // Khởi tạo object lớp Scanner
        System.out.print("Nhap so luong hang hoa: "); //  Yêu cầu nhập số lượng hàng hóa
        int n = scn.nextInt(); // Nhập số lượng hàng hóa

        DSH = new Hanghoa[n]; // Khởi tạo mảng Hàng hóa n phần tử
        for (int i = 0; i < n; i++) { // Dùng vòng lặp for nhập n hàng hóa
            System.out.println("\n\n\t\t\tQUAN LY SIEU THI"); // Menu
            System.out.println("1. Dien may");
            System.out.println("2. Sanh su");
            System.out.println("3. Thuc pham");
            System.out.print("Lua chon: ");
            int option = scn.nextInt(); // Nhập lựa chọn

            Hanghoa hh; // Khởi tạo 1 object Hàng hóa
            if (option == 1) // Kiểm tra xem lựa chọn là gì
                hh = new HangDienMay(); // Sau đó cho object trỏ đến class tương ứng
            else if (option == 2)
                hh = new HangSanhSu();
            else
                hh = new HangThucPham();
            hh.Nhap(); // Nhập thông tin hàng hóa

            for (int j = 0; j < i; j++) { // Dùng vòng lặp for kiểm tra xem có Hàng hóa trong DSH chưa
                if (hh.getMaHang().equalsIgnoreCase(DSH[i].getMaHang())) { // Kiểm tra Mã Hàng có trùng lặp không
                    System.out.println("Hang da ton tai!");
                    break;
                } else if (i == j) { // Nuếu không trùng lặp thì thêm vào danh sách DSH
                    DSH[i] = hh;
                    continue;
                }
            }
        }

        // Xuất danh sách các loại Hàng hóa
        System.out.println("Danh sach Hang Sanh Su: ");
        HangSanhSu.Title();
        for (int i = 0; i < n; i++)
            if (DSH[i] instanceof HangSanhSu)
                DSH[i].Xuat();

        System.out.println("Danh sach Hang Dien May: ");
        HangDienMay.Title();
        for (int i = 0; i < n; i++)
            if (DSH[i] instanceof HangDienMay)
                DSH[i].Xuat();

        System.out.println("Danh sach Hang Thuc Pham: ");
        HangThucPham.Title();
        for (int i = 0; i < n; i++)
            if (DSH[i] instanceof HangThucPham)
                DSH[i].Xuat();

        scn.close();
    }
}
