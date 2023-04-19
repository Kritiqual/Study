import java.util.Scanner; // Import thư viện cần thiết

public abstract class Hanghoa { // Khai báo lớp Hàng hóa
    protected String maHang, tenHang, ghiChu; // Khai báo các thuộc tính
    protected int slgTon, donGia;
    protected double VAT;

    public abstract String DanhGia(); // Khai báo phương thức Đánh giá với chỉ thị abstract

    static void Title() { // Phương thức để in ra dòng tiêu đề
        System.out.printf("%10s %20s %10d %10d %5d", "Ma Hang", "Ten Hang", "So luong ton", "Don Gia", "VAT");
    }

    public String getMaHang() {
        return this.maHang;
    }

    public void Nhap() { // Phương thức nhập các thuộc tính
        try (Scanner scn = new Scanner(System.in)) {
            System.out.print("Nhap Ma Hang: ");
            maHang = scn.nextLine();
            System.out.println("Nhap Ten Hang: ");
            tenHang = scn.nextLine();
            System.out.println("Nhap Don Gia: ");
            donGia = scn.nextInt();
            System.out.println("Nhap Ton Kho: ");
            slgTon = scn.nextInt();
            scn.nextLine();
        }
    }

    public void Xuat() { // Phương thức xuất các thông tin
        System.out.printf("%10s %10s %10d %10d %10.1f", maHang, tenHang, donGia, slgTon, VAT);
    }
}
