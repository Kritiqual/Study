import java.util.Calendar; // Import các thư viện cần thiết
import java.util.Date;
import java.util.Scanner;

class HangSanhSu extends Hanghoa { // Khai báo lớp Hàng Sành sứ kế thừa lớp Hàng hóa
    private String nhaSX; // Khai báo các thuộc tính
    private NT ngayNhapKho;

    public String DanhGia() { // Phương thức Đánh giá theo yêu cầu bài toán
        Calendar c = Calendar.getInstance();
        Date d = c.getTime();
        c.set(ngayNhapKho.getY(), ngayNhapKho.getM() - 1, ngayNhapKho.getD());
        c.roll(Calendar.DAY_OF_MONTH, 10);
        if (slgTon > 50 && d.compareTo(c.getTime()) > 0)
            return "Ban cham";
        return "Binh thuong";
    }

    public void Nhap() { // Phương thức nhập thuộc tính
        super.Nhap();
        try (Scanner scn = new Scanner(System.in)) {
            System.out.println("Nhap Nha SX: ");
            nhaSX = scn.nextLine();
        }
        System.out.println("Nhap Ngay Nhap Kho: ");
        ngayNhapKho = new NT();
        ngayNhapKho.Nhap();
        ghiChu = DanhGia();
        VAT = 0.1;
    }

    static void Title() { // Phương thức hiển thị tiêu đề
        Hanghoa.Title(); // Hiển thị dòng tiêu đề kế thừa từ lớp cha
        System.out.printf("%20s %15s %20s", "Nha San xuat", "Ngay Nhap kho", "Ghi chu");
    }

    public void Xuat() { // Phương thức Xuất thông tin
        super.Xuat(); // Hiển thị thông tin kế thừa từ lớp cha
        System.out.printf("%20s %15s %20s", nhaSX, ngayNhapKho, ghiChu);
    }
}
