import java.util.Scanner; // Import thư viện cần thiết

class HangDienMay extends Hanghoa { // Khai báo lớp Hàng điện máy kế thừa lớp Hàng hóa
    private int thoiGianBaoHanh, congSuat; // Khai báo thuộc tính

    public String DanhGia() { // Phương thức Đánh giá theo yêu cầu bài toán
        if (slgTon < 3)
            return "Ban duoc";
        return "Binh thuong";
    }

    public void Nhap() { // Phương thức nhập các thuộc tính
        super.Nhap(); // Nhập thông tin kế thừa từ lớp cha
        try (Scanner scn = new Scanner(System.in)) {
            System.out.println("Nhap Thoi Gian Bao Hanh: ");
            thoiGianBaoHanh = scn.nextInt();
            System.out.println("Nhap Cong Suat: ");
            congSuat = scn.nextInt();
        }
        ghiChu = DanhGia();
        VAT = 0.1;
    }

    static void Title() { // Phương thức hiển thị dòng tiêu đề
        Hanghoa.Title(); // Hiển thị tiêu đề kế thưa từ lớp cha
        System.out.printf("%10s %10s %20s", "Thoi gian bao hanh", "Cong suat", "Ghi chu");
    }

    public void Xuat() { // Phương thức xuất thông tin
        super.Xuat(); // Xuất thông tin kế thừa từ lớp cha
        System.out.printf("%10d %10d %20s", thoiGianBaoHanh, congSuat, ghiChu);
    }
}
