import java.util.Calendar; // Import các thư viện cần thiết
import java.util.Date;
import java.util.Scanner;

class HangThucPham extends Hanghoa { // Khai báo lớp Hàng Thực phẩm kế thừa từ lớp Hàng hóa
    private NT ngaySX, ngayHetHan; // Khai báo các thuộc tính
    private String nhaCungCap;

    public String DanhGia() { // Phương thức đánh giá theo yêu cầu bài toán
        Calendar c = Calendar.getInstance();
        Date d = c.getTime();
        c.set(ngayHetHan.getY(), ngayHetHan.getM() - 1, ngayHetHan.getD());
        if ((slgTon != 0) && (d.compareTo(c.getTime())) > 0)
            return "Kho ban";
        return "Binh thuong";
    }

    public void Nhap() { // Phương thức nhập các thuộc tính
        super.Nhap();
        try (Scanner scn = new Scanner(System.in)) {
            System.out.println("Nhap Nha Cung cap: ");
            nhaCungCap = scn.nextLine();
        }
        System.out.println("Nhap Ngay SX: ");
        ngaySX = new NT();
        ngaySX.Nhap();
        System.out.println("Nhap Ngay Het han: ");
        ngayHetHan = new NT();
        ngayHetHan.Nhap();
        ghiChu = DanhGia();
        VAT = 0.05;
    }

    static void Title() { // Phương thức hiển thị dòng tiêu đề
        Hanghoa.Title(); // Hiển thị dòng tiêu đề kế thừa từ lớp cha
        System.out.printf("%20s %15s %15s %20s", "Nha San xuat", "Ngay nhap kho", "Ngay het han", "Ghi Chu");
    }

    public void Xuat() { // Phương thức hiển thị thông tin
        super.Xuat(); // Hiển thị thông tin kế thừa từ lớp cha
        System.out.printf("%15s %15s %20s %20s", ngaySX, ngayHetHan, nhaCungCap, ghiChu);
    }
}
